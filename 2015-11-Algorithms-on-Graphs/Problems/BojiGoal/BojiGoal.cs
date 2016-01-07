namespace BojiGoal
{
    using System;
    using System.Linq;

    class Startup
    {
        private static int n;

        private static int[,] matrix;
        private static int[] used;

        private static int start;

        private static long currentSum;
        private static long minSum;

        private static void Main(string[] args)
        {
            ProcessInput();

            minSum = long.MaxValue;
            currentSum = 0;

            // Solution
            Hamiltonian(start, 0);

            if (minSum < long.MaxValue)
            {
                Console.WriteLine(minSum);
            }
            else
            {
                Console.WriteLine(0);
            }
        }

        private static void ProcessInput()
        {
            n = int.Parse(Console.ReadLine());
            start = int.Parse(Console.ReadLine()) - 1;

            used = new int[n];
            matrix = new int[n, n];

            var line = Console.ReadLine();
            while (line != "end")
            {
                var data = line.Split(' ').Select(int.Parse).ToArray();

                // The graph is unoriented so we assign the values two way
                matrix[data[0] - 1, data[1] - 1] = data[2];
                matrix[data[1] - 1, data[0] - 1] = data[2];

                line = Console.ReadLine();
            }
        }


        private static void Hamiltonian(int i, int level)
        {
            if (start == i && level > 0 && level == n)
            {
                minSum = currentSum;
                return;
            }

            if (used[i] != 0)
            {
                return;
            }

            used[i] = 1;

            for (int k = 0; k < n; k++)
            {
                if (matrix[i, k] != 0 && k != i)
                {
                    currentSum += matrix[i, k];

                    if (currentSum < minSum)
                    {
                        Hamiltonian(k, level + 1);
                    }

                    currentSum -= matrix[i, k];
                }
            }

            used[i] = 0;
        }

        // Adjecent matrix printing for check
        private static void PrintAdjacentMatrix()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}

