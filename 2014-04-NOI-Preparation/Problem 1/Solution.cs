namespace ColorLines
{
    using System;
    using System.Linq;

    public class ColorLinesProgram
    {
        public static void Main()
        {
            int[] rowsAndCols = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            int rows = rowsAndCols[0];
            int cols = rowsAndCols[1];

            char[,] canvas = new char[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                string line = Console.ReadLine();
                for (int j = 0; j < cols; j++)
                {
                    canvas[i, j] = line[j];
                }
            }

            int answer = Solve(canvas);
            Console.WriteLine(answer);
        }

        private static int Solve(char[,] canvas)
        {
            int answer = 0;
            // check for red lines

            for (int i = 0; i < canvas.GetLength(0); i++)
            {
                bool inRed = false;
                for (int j = 0; j < canvas.GetLength(1); j++)
                {
                    if (canvas[i, j] == 'R' || canvas[i, j] == 'G')
                    {
                        if (!inRed)
                        {
                            answer++;
                            inRed = true;
                        }
                    }
                    else
                    {
                        inRed = false;
                    }
                }
            }

            for (int i = 0; i < canvas.GetLength(1); i++)
            {
                bool inBlue = false;
                for (int j = 0; j < canvas.GetLength(0); j++)
                {
                    if (canvas[j, i] == 'B' || canvas[j, i] == 'G')
                    {
                        if (!inBlue)
                        {
                            answer++;
                            inBlue = true;
                        }
                    }
                    else
                    {
                        inBlue = false;
                    }
                }
            }

            return answer;
        }
    }
}
