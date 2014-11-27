namespace GraphHelpers
{
    using System.Collections.Generic;

    public static class Bfs
    {
        public static int Traverse(HashSet<string> words, string startWord, string toWord)
        {
            var queue = new Queue<KeyValuePair<string, short>>();
            var usedWords = new HashSet<string>();
            queue.Enqueue(new KeyValuePair<string, short>(startWord, 0));

            while (queue.Count > 0)
            {
                var lastWord = queue.Dequeue();

                if (lastWord.Key == toWord)
                {
                    return lastWord.Value;
                }

                if (usedWords.Contains(lastWord.Key))
                {
                    continue;
                }

                usedWords.Add(lastWord.Key);

                var adjacentWords = FindAdjacentWords(lastWord.Key, words);
                foreach (var adjacentWord in adjacentWords)
                {
                    queue.Enqueue(new KeyValuePair<string, short>(adjacentWord, (short)(lastWord.Value + 1)));
                }
            }

            return 0;
        }

        /// <summary>
        /// Accepts 2 different lowercased words and returns true if only one letter differentiates them
        /// </summary>
        public static bool IsValidWord(string fromWord, string toWord)
        {
            var foundOneChangingCharacter = false;

            for (int i = 0; i < fromWord.Length; i++)
            {
                if (fromWord[i] != toWord[i] && !foundOneChangingCharacter)
                {
                    foundOneChangingCharacter = true;
                }
                else if (fromWord[i] != toWord[i] && foundOneChangingCharacter)
                {
                    return false;
                }
            }

            // If only one changing char was found will return true; else false
            return foundOneChangingCharacter;
        }

        private static IEnumerable<string> FindAdjacentWords(string lastWord, HashSet<string> words)
        {
            var adjacentWords = new List<string>();

            foreach (var word in words)
            {
                if (IsValidWord(lastWord, word))
                {
                    adjacentWords.Add(word);
                }
            }

            return adjacentWords;
        }
    }
}