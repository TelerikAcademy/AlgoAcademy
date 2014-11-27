using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CubicRoot
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger number = BigInteger.Parse(Console.ReadLine());

            BigInteger highBound = number;
            BigInteger lowBound = 0;
            BigInteger currentRoot = (lowBound + highBound) / 2;

            BigInteger rootPower3 = currentRoot * currentRoot * currentRoot;

            while (rootPower3 != number)
            {
                if (rootPower3 > number)
                {
                    highBound = currentRoot;
                    currentRoot = (currentRoot + lowBound) / 2;
                }
                else if (rootPower3 < number)
                {
                    lowBound = currentRoot;
                    currentRoot = (currentRoot + highBound) / 2;
                }

                rootPower3 = currentRoot * currentRoot * currentRoot;
            }

            Console.WriteLine(currentRoot);
        }
    }
}
