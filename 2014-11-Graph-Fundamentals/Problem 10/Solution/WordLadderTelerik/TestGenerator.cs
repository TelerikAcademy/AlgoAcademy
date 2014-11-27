using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace WordLadderTelerik
{
    public class TestGenerator
    {
        public const string FileNamesFormat = "test.{0:000}.in.txt";
        private static readonly Random Rand = new Random();
        private const int wordLimit = 2000;

        public void GenerateTests()
        {
            CreateStandartTest(5, 1);
            CreateStandartTest(5, 2);
            CreateStandartTest(5, 3);
            CreateStandartTest(5, 4);
            CreateStandartTest(5, 5);
            CreateStandartTest(5, 6);
            CreateStandartTest(5, 7);
            CreateStandartTest(5, 8);
            CreateStandartTest(5, 9);
            CreateStandartTest(5, 10);
        }

        private void CreateNoTest(string startWord, string endWord, int testNumber)
        {
            string[] newFile;


            newFile = File.ReadAllLines("words.txt");

        }

        private void CreateStandartTest(int wordLength, int testNumber)
        {
            string[] newFile;
            newFile = File.ReadAllLines(wordLength+"letterWords.txt");

            var wordList = new List<string>(newFile);

            using (var sw = new StreamWriter(string.Format(FileNamesFormat, testNumber)))
            {
                var startWordIndex = Rand.Next(0, wordList.Count);
                var startWord = wordList[startWordIndex];
                sw.WriteLine(startWord);

                var endWordIndex = Rand.Next(0, wordList.Count);
                var endWord = wordList[endWordIndex];
                sw.WriteLine(endWord);

                for (int i = 0; i < wordList.Count; i++)
                {
                    sw.WriteLine(wordList[i]);
                }

                sw.WriteLine(string.Empty);


                Console.WriteLine("Test {0} is ready!", testNumber);
            }
        }
    }
}