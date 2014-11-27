namespace WordLadderTelerik
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using GraphHelpers;

    public class WordLadder
    {
        private static void Main(string[] args)
        {
            if (Environment.CurrentDirectory.ToLower().EndsWith("bin\\debug"))
            {
                Console.SetIn(new StreamReader("test.008.in.txt"));
            }

            var startWord = Console.ReadLine();
            var endWord = Console.ReadLine();
            var wordLength = startWord.Length;
            var words = new HashSet<string>();

            while (true)
            {
                var currentWord = Console.ReadLine();

                if (string.IsNullOrEmpty(currentWord))
                {
                    break;
                }

                if (currentWord.Length == wordLength)
                {
                    words.Add(currentWord);
                }
            }

            var numberOfTransformations = Bfs.Traverse(words, startWord, endWord);

            Console.WriteLine(numberOfTransformations == 0 ? "NO" : numberOfTransformations.ToString());
        }
    }
}
