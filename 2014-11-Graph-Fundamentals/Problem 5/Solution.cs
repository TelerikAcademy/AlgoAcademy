using System;
using System.Collections.Generic;

namespace Friends
{
    public class Program
    {
        public static IDictionary<string, HashSet<string>> graph = new Dictionary<string, HashSet<string>>();
        public static HashSet<string> visited = new HashSet<string>();

        public static int max = 0;

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            string k = Console.ReadLine();
            for (int i = 0; i < n; i++)
            {
                string[] connections = Console.ReadLine().Split(' ');
                string firstFriend = connections[0];
                string secondFriend = connections[1];

                AddFriends(firstFriend, secondFriend);
                AddFriends(secondFriend, firstFriend);
            }

            TheBiggestGroup(k, 1);

            Console.WriteLine(max);
        }

        private static void TheBiggestGroup(string current, int count)
        {
            if (visited.Contains(current) || !graph.ContainsKey(current))
            {
                return;
            }

            if (count > max)
            {
                max = count;
            }

            visited.Add(current);

            var friends = graph[current];
            foreach (var friend in friends)
            {
                TheBiggestGroup(friend, count + 1);
            }

            visited.Remove(current);
        }

        private static void AddFriends(string firstFriend, string secondFriend)
        {
            if (!graph.ContainsKey(firstFriend))
            {
                graph.Add(firstFriend, new HashSet<string>());
            }

            graph[firstFriend].Add(secondFriend);
        }
    }
}
