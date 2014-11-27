using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        if (Debugger.IsAttached || args.Length != 0)
        {
            Console.SetIn(new StreamReader(@"D:\_lib\_workbench\ta-problems\needle-haystack-ocean\test-generator\bin\debug\test.006.in.txt"));

        }
        
        var firstLineInts = Console.ReadLine().Split(' ').Select(int.Parse);
        var hay = GetInts(firstLineInts.First());
        var needles = GetInts(firstLineInts.Skip(1).First());
        
        bool firstNeedle = true;

        foreach (int needle in needles)
        {
            int lowEnd = -1;
            int highEnd = hay.Count;
            
            while (true)
            {
                // position we're looking for
                int? found = null;

                Debug.Assert(lowEnd == -1 || hay[lowEnd] < needle);
                Debug.Assert(highEnd == hay.Count || needle < hay[highEnd]);

                // binary search reached vanishing point?
                if (highEnd - lowEnd == 1)
                {
                    found = highEnd;
                }
                else
                {
                    // probe in middle
                    int thisProbe = (lowEnd + highEnd) / 2;
                    
                    // if we land in bunch of 0s
                    if (hay[thisProbe] == 0)
                    {
                        int leftEnd = thisProbe;
                        
                        // check what's on the left side
                        while (leftEnd > lowEnd && hay[leftEnd] == 0)
                            leftEnd -= 1;

                        // if it's less than needle, we need to check the other side as well
                        if (leftEnd == -1 || hay[leftEnd] < needle)
                        {
                            int rightEnd = thisProbe;
                            while (rightEnd < highEnd && hay[rightEnd] == 0)
                                rightEnd += 1;

                            // todo: test for out of range condition

                            // if we landed so that hay[leftEnd] < needle <= hay[rightEnd]
                            if (rightEnd == highEnd || needle <= hay[rightEnd])
                                // we can insert the 'needle' at the left end of the 0s
                                found = leftEnd + 1;
                            else
                                // otherwise, pretend we've probed at the right end 
                                // instead of inside the 0s
                                thisProbe = rightEnd;
                        }
                        else 
                        {
                            // pretend we've probed at the left end of the 0s
                            thisProbe = leftEnd;
                        }
                        
                    }
                    
                    // if we've hit a bunch of values equal to needle
                    if (thisProbe >= 0 && thisProbe < hay.Count && hay[thisProbe] == needle)
                    {
                        // find the leftmost of them (optionally skipping 0s)
                        
                        int insertPos = thisProbe;
                        while (insertPos > 0 &&
                               (hay[insertPos - 1] == needle || hay[insertPos - 1] == 0))
                            insertPos -= 1;

                        found = insertPos;

                    }
                    
                    if (found == null)
                    {
                        Debug.Assert(hay[thisProbe] != 0);

                        // choose next probing range
                        
                        if (needle < hay[thisProbe])
                            highEnd = thisProbe;
                        else
                            lowEnd = thisProbe;
                    }
                }

                if (found != null)
                {
                    if (firstNeedle)
                        firstNeedle = false;
                    else
                        Console.Write(" ");

                    Console.Write(found);
                    break;
                }
                
            }
        }

    }

    // efficiently reads a bunch of integers from the console into a list
    static List<int> GetInts(int intsCount)
    {
        var ints = new List<int>(intsCount); // return value
        int currentNumber = 0;
        while (true)
        {
            int thisChar = Console.In.Peek();
            if (char.IsNumber((char)thisChar))
            {
                currentNumber *= 10;
                currentNumber += (thisChar - '0');
            }
            else
            {
                ints.Add(currentNumber);
                currentNumber = 0;
                if (thisChar == '\r' || thisChar == '\n' || thisChar == -1)
                {
                    Debug.Assert(intsCount == ints.Count);
                    Console.ReadLine();
                    return ints;
                }
            }
            Console.Read();
        }
    }
}