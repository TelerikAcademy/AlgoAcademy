using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TestGenerator
{
    class Program
    {
        static readonly Random Rand = new Random();
        const string logFile = "win-lose.txt";

        static void Main(string[] args)
        {
            int gamesCount = Rand.Next(1, 10);
            Console.WriteLine(gamesCount);

            for (int gameInd = 0; gameInd < gamesCount; gameInd++)
            {
                int N = Rand.Next(9, 100);
                int M = Rand.Next(200, 300);
                int K = Rand.Next(1, N);

                Console.WriteLine(K);
                Console.WriteLine(N);
                Console.WriteLine(M);

                bool ensureLosing = Rand.Next(2) == 0 ? true : false;

                var winLoseLines = System.IO.File.ReadAllLines(logFile);

                if (ensureLosing)
                {
                    System.IO.File.AppendAllText(logFile, "lose: " + winLoseLines.Length + System.Environment.NewLine);

                    HashSet<int> colsToFill = new HashSet<int>();

                    int colsToFillCount = Rand.Next(3, 25);
                    for (int x = 0; x < colsToFillCount; x++)
                    {
                        colsToFill.Add(Rand.Next(0, 7));
                    }

                    var diffStrings = new List<StringBuilder>();
                    for (int i = 0; i < N; i++)
                    {
                        diffStrings.Add(new StringBuilder(new string('0', 8)));
                    }

                    foreach (var col in colsToFill)
                    {
                        for (int diffInd = 0; diffInd < K+1; diffInd++)
                        {
                            diffStrings[diffInd][col] = '1';
                        }
                    }

                    var diffNums = new List<int>();
                    foreach (var strBuilder in diffStrings)
                    {
                        diffNums.Add(Convert.ToInt32(String.Join("", strBuilder.ToString().Reverse()), 2));
                    }


                    foreach (var diff in diffNums)
                    {
                        int right = Rand.Next(diff, M);
                        int left = right - diff;

                        Console.WriteLine(left + " " + right);
                    }
                }
                else
                {
                    System.IO.File.AppendAllText(logFile, "win: " + winLoseLines.Length + System.Environment.NewLine);

                    for (int row = 0; row < N; row++)
                    {
                        Console.WriteLine(Rand.Next(0, M) + " " + Rand.Next(0, M));
                    }
                }
            }
        }
    }
}
