namespace PositiveStrings
{
    using System;
    using System.Text;

    public static class Program
    {
        public static void Main()
        {
            var template = Console.ReadLine();
            var positiveString = FindPositiveString(template);
            Console.WriteLine(positiveString);
        }

        private static string FindPositiveString(string template)
        {
            template += ",";
            if (!CanComplete(template))
            {
                return "invalid";
            }
            
            for (int i = 0; i < template.Length; ++i)
            {
                if (template[i] == '?')
                {
                    foreach (var ch in ",0123456789")
                    {
                        // Place ch on ith position
                        var current = template.Substring(0, i) + ch + template.Substring(i + 1);
                        if (CanComplete(current))
                        {
                            template = current;
                            break;
                        }
                    }
                }
            }

            return template.Substring(0, template.Length - 1);
        }

        private static bool CanComplete(string template)
        {
            var minEnd = new string[template.Length + 1];
            minEnd[0] = string.Empty;
            for (var i = 0; i < template.Length; ++i)
            {
                if ((template[i] == '?' || template[i] == ',') && i > 0)
                {
                    string best = null;
                    for (var j = i - 1; j >= 0; --j)
                    {
                        if (template[j] == ',')
                        {
                            break;
                        }

                        if (minEnd[j] == null)
                        {
                            continue;
                        }

                        string cur = GetMinimal(template.Substring(j, i - j), minEnd[j]);
                        if (cur != null)
                        {
                            if (best == null || cur.Length < best.Length || cur.Length == best.Length && cur.CompareTo(best) < 0)
                            {
                                best = cur;
                            }
                        }
                    }

                    minEnd[i + 1] = best;
                }
            }

            return minEnd[template.Length] != null;
        }

        private static string GetMinimal(string first, string second)
        {
            if (first.Length == 0 || first[0] == '0')
            {
                return null;
            }

            if (first.Length < second.Length)
            {
                return null;
            }

            var already = first.Length > second.Length;
            bool[] canBeBigger = null;
            if (!already)
            {
                canBeBigger = new bool[first.Length + 1];
                var can = false;
                for (var i = first.Length - 1; i >= 0; --i)
                {
                    if (first[i] == '?')
                    {
                        if (second[i] != '9')
                        {
                            can = true;
                        }
                    }
                    else
                    {
                        if (first[i] > second[i])
                        {
                            can = true;
                        }
                        else if (first[i] < second[i])
                        {
                            can = false;
                        }
                    }

                    canBeBigger[i] = can;
                }

                if (!canBeBigger[0])
                {
                    return null;
                }
            }

            var stringBuilder = new StringBuilder();
            for (int i = 0; i < first.Length; ++i)
            {
                if (first[i] == '?')
                {
                    if (already)
                    {
                        if (i == 0)
                        {
                            stringBuilder.Append('1');
                        }
                        else
                        {
                            stringBuilder.Append('0');
                        }
                    }
                    else
                    {
                        if (canBeBigger[i + 1])
                        {
                            stringBuilder.Append(second[i]);
                        }
                        else
                        {
                            already = true;
                            stringBuilder.Append((char)(second[i] + 1));
                        }
                    }
                }
                else
                {
                    stringBuilder.Append(first[i]);
                    if (!already)
                    {
                        if (first[i] > second[i])
                        {
                            already = true;
                        }

                        if (first[i] < second[i])
                        {
                            // Should never happen 
                            return null;
                        }
                    }
                }
            }

            return stringBuilder.ToString();
        }
    }
}
