using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrecisionSolution.cs
{
    class Program
    {
        static void Main()
        {
            int maxDen = int.Parse(Console.ReadLine());
            string number = Console.ReadLine();
            findFraction(maxDen, number);
        }

        public static int Quality(string number, int up, int down)
        {
            int res = 1;

            int cur = 2;
            while (true)
            {
                if ((10 * up) / down == number[cur] - '0')
                    res++;
                else
                    break;

                cur++;
                if (cur == number.Length) break;
                up *= 10;
                up %= down;
            }

            return res;
        }

        public static void findFraction(int maxDen, string number)
        {
            string now = "";
            int nowQuality = 0;
            string toDouble = "";

            for (int i = 0; i < 14 && i < number.Length; i++)
            {
                toDouble += number[i];
            }
            double num = Convert.ToDouble(toDouble);

            for (int i = 1; i <= maxDen; i++)
            {
                int left = 0, right = i;
                while (right - left > 1)
                {
                    int avg = (right + left) / 2;
                    double avgVal = (double)avg / i;
                    if (avgVal > num) right = avg;
                    else left = avg;
                }
                left -= 1;
                right += 1;
                if (left < 0) left = 0;
                if (right > i) right = i;

                for (int k = left; k <= right; k++)
                {
                    int abcd = Quality(number, k, i);
                    if (abcd > nowQuality)
                    {
                        nowQuality = abcd;
                        now = k.ToString() + '/' + i.ToString();
                    }
                }
            }

            Console.WriteLine(now);
            Console.WriteLine(nowQuality);
        }
    }
}
