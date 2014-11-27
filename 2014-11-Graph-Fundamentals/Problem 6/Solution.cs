namespace NumbersMagic
{
    using System;
    using System.Collections.Generic;

    public class Program
    {
        public static IDictionary<char, HashSet<char>> graph = new Dictionary<char, HashSet<char>>();
        public static HashSet<char> visited = new HashSet<char>();
        public static SortedSet<long> results = new SortedSet<long>();

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            List<string> numbers = new List<string>();
            for (int i = 0; i < n; i++)
            {
                string currentNumber = Console.ReadLine();
                numbers.Add(currentNumber);
            }

            GenerateGraphFromNumbers(numbers);

            for (char i = '1'; i <= '9'; i++)
            {
                if (graph.ContainsKey(i))
                {
                    visited = new HashSet<char>();
                    AddNumbers(i, "");
                }
            }

            foreach (var number in results)
            {
                Console.WriteLine(number);
            }
        }

        public static void AddNumbers(char currentNumber, string result)
        {
            if (visited.Contains(currentNumber))
            {
                results.Add(long.Parse(result));
                return;
            }

            visited.Add(currentNumber);
            result = string.Format("{0}{1}", result, currentNumber);
            var children = graph[currentNumber];
            foreach (var child in children)
            {
                AddNumbers(child, result);
            }

            visited.Remove(currentNumber);

            if (children.Count == 0)
            {
                results.Add(long.Parse(result));
            }
        }

        public static void GenerateGraphFromNumbers(List<string> numbers)
        {
            foreach (var number in numbers)
            {
                for (int i = 0; i < number.Length - 1; i++)
                {
                    var currentDigit = number[i];
                    if (!graph.ContainsKey(currentDigit))
                    {
                        graph.Add(currentDigit, new HashSet<char>());
                    }

                    var nextDigit = number[i + 1];
                    graph[currentDigit].Add(nextDigit);
                    if (!graph.ContainsKey(nextDigit))
                    {
                        graph.Add(nextDigit, new HashSet<char>());
                    }
                }
            }
        }
    }
}
