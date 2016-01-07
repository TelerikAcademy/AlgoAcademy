namespace GraphGenerator
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;
    using System.IO;
    using System.Linq;
    using System.Text;

    public class Startup
    {
        private static IDictionary<string, int[]> districts;

        public static void Main()
        {
            Console.WriteLine(Solve());
        }

        public static string Solve()
        {
            var n = int.Parse(Console.ReadLine());

            districts = new Dictionary<string, int[]>(n);

            for (int i = 0; i < n; i++)
            {
                var districtInfo = Console.ReadLine().Split(' ');
                var edgeCount = int.Parse(districtInfo[2]);
                var nodes = new int[int.Parse(districtInfo[1])];

                districts.Add(districtInfo[0], nodes);

                for (int j = 0; j < edgeCount; j++)
                {
                    var currentEdge = Console.ReadLine().Split(' ').Select(x => int.Parse(x) - 1).ToArray();

                    // the task is about euler paths and cycles in undirected connected graphs
                    // so it's enough just to keep track of the degrees of the nodes
                    nodes[currentEdge[0]]++;
                    nodes[currentEdge[1]]++;
                }
            }

            var result = string.Join(Environment.NewLine, districts.Select(kvp =>
            {
                var oddNodesCount = kvp.Value.Sum(x => x % 2);

                switch (oddNodesCount)
                {
                    case 0:
                        return kvp.Key + " Wolf";
                    case 2:
                        return kvp.Key + " Titan";
                    default:
                        return kvp.Key + " Dirty";
                }
            }).ToArray());

            return result;
        }

        /// <summary>
        /// Outs execution times for tests in a .txt file.
        /// </summary>
        /// <param name="testLocationTemplate"></param>
        /// <param name="testCount"></param>
        //public static void GetAuthorSolutionExecutionTime(string testLocationTemplate, int testCount)
        //{
        //    var watch = new Stopwatch();
        //    var results = new StringBuilder();
        //    for (int i = 1; i <= testCount; i++)
        //    {
        //        Console.SetIn(new StringReader(File.ReadAllText(string.Format(testLocationTemplate, i))));
        //        watch.Restart();
        //        Solve();
        //        watch.Stop();

        //        results.AppendLine(i + " - " + watch.Elapsed.ToString());
        //    }

        //    File.WriteAllText("../../tests/timeinfo.txt", results.ToString());
        //}
    }
}