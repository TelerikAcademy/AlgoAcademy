namespace Portals
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class PortalsProgram
    {
        private static int[,] labyrinth;
        private static int maxResult = 0;

        public static void BFS(Position currentPosition)
        {
            if (currentPosition.Power > maxResult)
            {
                maxResult = currentPosition.Power;
            }

            labyrinth = currentPosition.CurrentState;
            var currentPowerLever = labyrinth[currentPosition.Row, currentPosition.Col];
            if (currentPowerLever > 0)
            {
                var nextPowerLevel = currentPosition.Power + currentPowerLever;

                // up
                var up = currentPosition.Row - currentPowerLever;
                if (up >= 0 && labyrinth[up, currentPosition.Col] != -1)
                {
                    labyrinth[currentPosition.Row, currentPosition.Col] = 0;
                    BFS(new Position { Row = up, Col = currentPosition.Col, Power = nextPowerLevel, CurrentState = GetState(labyrinth)});
                    labyrinth[currentPosition.Row, currentPosition.Col] = currentPowerLever;
                }

                // down
                var down = currentPosition.Row + currentPowerLever;
                if (down < labyrinth.GetLength((0)) && labyrinth[down, currentPosition.Col] != -1)
                {
                    labyrinth[currentPosition.Row, currentPosition.Col] = 0;
                    BFS(new Position { Row = down, Col = currentPosition.Col, Power = nextPowerLevel, CurrentState = GetState(labyrinth)});
                    labyrinth[currentPosition.Row, currentPosition.Col] = currentPowerLever;
                }

                // left
                var left = currentPosition.Col - currentPowerLever;
                if (left >= 0 && labyrinth[currentPosition.Row, left] != -1)
                {
                    labyrinth[currentPosition.Row, currentPosition.Col] = 0;
                    BFS(new Position { Row = currentPosition.Row, Col = left, Power = nextPowerLevel, CurrentState = GetState(labyrinth) });
                    labyrinth[currentPosition.Row, currentPosition.Col] = currentPowerLever;
                }

                // right
                var right = currentPosition.Col + currentPowerLever;
                if (right < labyrinth.GetLength(1) && labyrinth[currentPosition.Row, right] != -1)
                {
                    labyrinth[currentPosition.Row, currentPosition.Col] = 0;
                    BFS(new Position { Row = currentPosition.Row, Col = right, Power = nextPowerLevel, CurrentState = GetState(labyrinth) });
                    labyrinth[currentPosition.Row, currentPosition.Col] = currentPowerLever;
                }
            }
        }

        public static void Main()
        {
            int[] startingPosition = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int startRow = startingPosition[0];
            int startCol = startingPosition[1];
            int[] dimensions = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int rows = dimensions[0];
            int cols = dimensions[1];
            labyrinth = new int[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                string[] currentRow = Console.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int j = 0; j < currentRow.Length; j++)
                {
                    if (currentRow[j] != "#")
                    {
                        labyrinth[i, j] = int.Parse(currentRow[j]);
                    }
                    else
                    {
                        labyrinth[i, j] = -1;
                    }
                }
            }

            BFS(new Position { Row = startRow, Col = startCol, Power = 0, CurrentState = labyrinth});
            Console.WriteLine(maxResult);
        }

        public static int[,] GetState(int[,] state)
        {
            var newArray = new int[state.GetLength((0)), state.GetLength(1)];
            for (int i = 0; i < state.GetLength(0); i++)
            {
                for (int j = 0; j < state.GetLength(1); j++)
                {
                    newArray[i, j] = state[i, j];
                }
            }

            return newArray;
        }

        public struct Position
        {
            public int Row { get; set; }

            public int Col { get; set; }

            public int Power { get; set; }

            public int[,] CurrentState { get; set; }
        }
    }
}
