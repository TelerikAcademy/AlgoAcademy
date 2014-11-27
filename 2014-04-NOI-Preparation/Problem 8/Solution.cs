using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ItemsItems
{
    class Program
    {
        static int[,] lab;
        static int[,] graph;
        static int[] itemRows;
        static int[] itemCols;
        static int[] obstacleTopRows;
        static int[] obstacleBottomRows;
        static int[] obstacleLeftCols;
        static int[] obstacleRightCols;

        static int[] rowsD = { 0, 1, 0, -1 };
        static int[] colsD = { 1, 0, -1, 0 };

        public static void Main()
        {
            //read N, I, O
            ReadInput();

            GenerateGraph();

            //PrintGraph();

            var bestTime = CalculateTime();
            Console.WriteLine(bestTime);
        }

        private static void PrintGraph()
        {
            for (int row = 0; row < graph.GetLength(0); row++)
            {
                for (int col = 0; col < graph.GetLength(1); col++)
                {
                    Console.Write((graph[row, col] + "").PadLeft(5) + " | ");
                }
                Console.WriteLine();

                if (row < graph.GetLength(0) - 1)
                {
                    for (int col = 0; col < graph.GetLength(1); col++)
                    {
                        Console.Write("----- | ");
                    }
                    Console.WriteLine();
                }
            }
        }

        private static int CalculateTime()
        {
            var perm = new int[itemRows.Length - 2];
            for (int i = 0; i < perm.Length; i++)
            {
                perm[i] = i + 1;
            }
            NextPermutation(perm, 0);

            return bestTime;
        }

        static int bestTime = int.MaxValue;

        private static void NextPermutation(int[] perm, int index)
        {
            if (index >= perm.Length - 1)
            {
                var thisTime = CalculateDistance(perm);
                if (thisTime < bestTime)
                {
                    bestTime = thisTime;
                }
            }
            else
            {
                for (var i = index; i < perm.Length; i++)
                {
                    var temp = perm[i];
                    perm[i] = perm[index];
                    perm[index] = temp;
                    NextPermutation(perm, index + 1);
                    temp = perm[i];
                    perm[i] = perm[index];
                    perm[index] = temp;

                }
            }
        }

        private static int CalculateDistance(int[] perm)
        {
            int time = 0;
            time += graph[0, perm[0]];
            for (var i = 0; i < perm.Length - 1; i++)
            {
                time += graph[perm[i], perm[i + 1]];
            }
            time += graph[perm[perm.Length - 1], graph.GetLength(0) - 1];
            return time;
        }

        private static void GenerateGraph()
        {
            graph = new int[itemRows.Length, itemCols.Length];
            for (var i = 0; i < itemRows.Length; i++)
            {
                InitLab();
                var distances = FindDistances(i);
                for (int endVertex = 0; endVertex < distances.Length; endVertex++)
                {
                    graph[i, endVertex] = distances[endVertex];
                }
            }
        }

        private static int[] FindDistances(int i)
        {
            int start = itemRows[i] * lab.GetLength(0) + itemCols[i];
            lab[itemRows[i], itemCols[i]] = 1;
            Queue<int> q = new Queue<int>();
            int[] distances = new int[itemRows.Length];
            q.Enqueue(start);
            while (q.Count > 0)
            {
                var current = q.Dequeue();
                int row = current / lab.GetLength(0);
                int col = current % lab.GetLength(0);
                for (int dir = 0; dir < rowsD.Length; dir++)
                {
                    var nextRow = row + rowsD[dir];
                    var nextCol = col + colsD[dir];
                    var inRange = InRange(nextRow, lab.GetLength(0)) &&
                        InRange(nextCol, lab.GetLength(1));
                    if (inRange && lab[nextRow, nextCol] <= 0)
                    {
                        if (lab[nextRow, nextCol] < 0)
                        {
                            var vertex = -lab[nextRow, nextCol] - 1;
                            distances[vertex] = lab[row, col];
                        }
                        lab[nextRow, nextCol] = lab[row, col] + 1;
                        q.Enqueue(nextRow * lab.GetLength(0) + nextCol);
                    }
                }
            }
            return distances;
        }

        private static bool InRange(int value, int max)
        {
            return 0 <= value && value < max;
        }

        private static void InitLab()
        {
            for (int row = 0; row < lab.GetLength(0); row++)
            {
                for (int col = 0; col < lab.GetLength(1); col++)
                {
                    lab[row, col] = 0;
                }
            }
            for (int i = 0; i < itemRows.Length; i++)
            {
                lab[itemRows[i], itemCols[i]] = -i - 1;
            }
            for (var o = 0; o < obstacleTopRows.Length; o++)
            {
                for (int row = obstacleTopRows[o]; row <= obstacleBottomRows[o]; row++)
                {
                    for (int col = obstacleLeftCols[o]; col <= obstacleRightCols[o]; col++)
                    {
                        lab[row, col] = int.MaxValue;
                    }
                }
            }
        }

        private static void ReadInput()
        {
            int[] nio = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            itemRows = new int[nio[1] + 2];
            itemCols = new int[nio[1] + 2];

            lab = new int[nio[0], nio[0]];
            //Console.WriteLine(String.Join(", ", nio));

            itemRows[0] = 0;
            itemCols[0] = 0;

            itemRows[itemRows.Length - 1] = nio[0] - 1;
            itemCols[itemCols.Length - 1] = nio[0] - 1;
            for (var i = 0; i < nio[1]; i++)
            {
                int[] item = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                itemRows[i + 1] = item[0];
                itemCols[i + 1] = item[1];
            }

           obstacleTopRows = new int[nio[2]];
           obstacleBottomRows = new int[nio[2]];
           obstacleLeftCols = new int[nio[2]];
           obstacleRightCols = new int[nio[2]];

            for (var i = 0; i < nio[2]; i++)
            {
                int[] obstacle = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                obstacleTopRows[i] = obstacle[0];
                obstacleLeftCols[i] = obstacle[1];
                obstacleBottomRows[i] = obstacle[2];
                obstacleRightCols[i] = obstacle[3];
            }
        }
    }
}