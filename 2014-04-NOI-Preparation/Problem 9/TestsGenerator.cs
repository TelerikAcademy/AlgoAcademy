using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestGenerator
{
    class Interval
    {
        public int First { get; set; }
        public int Last { get; set; }
        public string TransformName { get; set; }

        public Interval(int first, int last, string transformName)
        {
            this.First = first;
            this.Last = last;
            this.TransformName = transformName;
        }

        public override string ToString()
        {
            return this.TransformName + " " + this.First + " " + this.Last;
        }
    }

    class Vector2D
    {
        public double X { get; set; }
        public double Y { get; set; }

        public Vector2D(double x, double y)
        {
            this.X = x;
            this.Y = y;
        }

        public void Rotate(double angleRads)
        {
            double rotX = this.X * Math.Cos(angleRads) - this.Y * Math.Sin(angleRads),
                rotY = this.X * Math.Sin(angleRads) + this.Y * Math.Cos(angleRads);

            this.X = rotX;
            this.Y = rotY;
        }

        public void Translate(double x, double y)
        {
            this.X += x;
            this.Y += y;
        }

        public override string ToString()
        {
            return this.X + " " + this.Y;
        }
    }

    interface ITransform
    {
        void ApplyOn(Vector2D v);
    }

    class TranslateTransform : ITransform
    {
        private double x, y;

        public TranslateTransform(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public void ApplyOn(Vector2D v)
        {
            v.Translate(this.x, this.y);
        }

        public override string ToString()
        {
            return "move " + this.x + " " + this.y;
        }
    }

    class RotateTransform : ITransform
    {
        private double angleRads;

        public RotateTransform(double angleRads)
        {
            this.angleRads = angleRads;
        }

        public void ApplyOn(Vector2D v)
        {
            v.Rotate(this.angleRads);
        }

        public override string ToString()
        {
            return "rotate " + this.angleRads * 180 / Math.PI;
        }
    }

    class Program
    {
        const double TaskPI = 3.14159265359;

        const int MinGroups = 5;
        const int MaxGroups = 30;

        const int MinTransformsPerGroup = 3;
        const int MaxTransformsPerGroup = 200;

        const int MinPoints = 5;
        const int MaxPoints = 1000;

        const int MaxCoord = 1000;

        const int MinIntervals = 5;
        const int MaxIntervals = 1000;

        const int MaxOffset = 50;

        const int MaxGroupNameLength = 50;

        static readonly Random Rand = new Random();

        static void Main(string[] args)
        {
            for (int testNumber = 1; testNumber <= 10; testNumber++)
            {
                Console.WriteLine("---");

                Dictionary<string, List<ITransform>> transformGroups = new Dictionary<string, List<ITransform>>();

                int groupsCount = Rand.Next(MinGroups, MaxGroups + 1);

                Console.WriteLine("Test: " + testNumber);
                Console.WriteLine("Groups: " + groupsCount);

                GenerateTransformGroups(testNumber, transformGroups, groupsCount);

                int pointsCount = Rand.Next(MinPoints, MaxPoints + 1);
                List<Vector2D> points = GeneratePoints(pointsCount);

                int intervalsCount = Rand.Next(MinIntervals, MaxIntervals + 1);
                if (testNumber > 5)
                {
                    intervalsCount = Rand.Next((MinIntervals + MaxIntervals) / 2, MaxIntervals + 1);
                }
                List<Interval> intervals = GenerateIntervals(transformGroups.Keys.ToList(), pointsCount, intervalsCount);

                Console.WriteLine("Points: " + pointsCount);
                Console.WriteLine("Intervals: " + intervalsCount);
                
                Console.WriteLine("writing to disk...");

                GenerateTestInputFile(testNumber, transformGroups, points, intervals);

                Console.WriteLine("Answer calculation:");
                Console.Write("calculating transforms... ");
                
                DateTime preCalcTransforms = DateTime.Now;
                ApplyTransforms(points, transformGroups, intervals);
                DateTime postCalcTransforms = DateTime.Now;

                Console.WriteLine("time: " + (postCalcTransforms - preCalcTransforms));

                Console.WriteLine("calculating closest...");
                List<Vector2D> closestToCenter = GetClosestPointsToCenter(points);

                Console.WriteLine("saving answer to disk...");
                GenerateTestAnswerFile(testNumber, closestToCenter);
                GenerateTestDebugFile(testNumber, closestToCenter);

                Console.WriteLine("... done!");
            }
        }

        private static void GenerateTestAnswerFile(int testNumber, List<Vector2D> closestToCenter)
        {
            string testOutputFilename = "test." + testNumber.ToString().PadLeft(3, '0') + ".out.txt";

            System.IO.File.WriteAllText(testOutputFilename, DistanceToCenterSq(closestToCenter[0]).ToString());
        }

        private static void GenerateTestDebugFile(int testNumber, List<Vector2D> closestToCenter)
        {
            string testDebugFilename = "test." + testNumber.ToString().PadLeft(3, '0') + ".debug.txt";

            System.IO.File.WriteAllText(testDebugFilename, closestToCenter[0].ToString());
        }

        static double DistanceToCenterSq(Vector2D point)
        {
            return point.X * point.X + point.Y * point.Y;
        }

        private static List<Vector2D> GetClosestPointsToCenter(List<Vector2D> points)
        {
            double eps = 0.01;
            double minDistanceSq = DistanceToCenterSq(points[0]);

            List<Vector2D> closestToCenterWithEpsilon = new List<Vector2D>();

            foreach (var point in points)
            {
                double pointToCenterDistSq = DistanceToCenterSq(point);
                double diff = minDistanceSq - pointToCenterDistSq;
                if (diff > eps)
                {
                    minDistanceSq = pointToCenterDistSq;
                    closestToCenterWithEpsilon.Clear();
                    closestToCenterWithEpsilon.Add(point);
                }
                else if (diff >= 0)
                {
                    closestToCenterWithEpsilon.Add(point);
                }
            }

            return closestToCenterWithEpsilon;
        }

        private static void ApplyTransforms(List<Vector2D> points, Dictionary<string, List<ITransform>> transformGroups, List<Interval> intervals)
        {
            foreach (var interval in intervals)
            {
                var group = transformGroups[interval.TransformName];
                for (int pointInd = interval.First; pointInd <= interval.Last; pointInd++)
                {
                    foreach (var transform in group)
                    {
                        transform.ApplyOn(points[pointInd]);
                    }
                }
            }
        }

        private static void GenerateTestInputFile(int testNumber, Dictionary<string, List<ITransform>> transformGroups, List<Vector2D> points, List<Interval> intervals)
        {
            string testInputFilename = "test." + testNumber.ToString().PadLeft(3, '0') + ".in.txt";

            System.IO.File.WriteAllText(testInputFilename, transformGroups.Count + System.Environment.NewLine);
            foreach (var group in transformGroups)
            {
                System.IO.File.AppendAllText(testInputFilename, group.Key + System.Environment.NewLine); //group name
                System.IO.File.AppendAllText(testInputFilename, group.Value.Count + System.Environment.NewLine); //group transfroms count

                Console.WriteLine(group.Key);
                foreach (var transform in group.Value)
                {
                    System.IO.File.AppendAllText(testInputFilename, transform + System.Environment.NewLine);
                }
            }

            System.IO.File.AppendAllText(testInputFilename, points.Count + System.Environment.NewLine);
            foreach (var point in points)
            {
                System.IO.File.AppendAllText(testInputFilename, point + System.Environment.NewLine);
            }

            System.IO.File.AppendAllText(testInputFilename, intervals.Count + System.Environment.NewLine);
            foreach (var interval in intervals)
            {
                System.IO.File.AppendAllText(testInputFilename, interval + System.Environment.NewLine);
            }
        }

        private static List<Interval> GenerateIntervals(List<string> groupNames, int pointsCount, int intervalsCount)
        {
            List<Interval> intervals = new List<Interval>();

            for (int i = 0; i < intervalsCount; i++)
            {
                int f = Rand.Next(pointsCount / 2);
                int l = Rand.Next(f + 1, pointsCount);
                intervals.Add(new Interval(f, l, groupNames[Rand.Next(groupNames.Count)]));
            }
            return intervals;
        }

        private static List<Vector2D> GeneratePoints(int pointsCount)
        {
            List<Vector2D> points = new List<Vector2D>();

            for (int i = 0; i < pointsCount; i++)
            {
                double x = Rand.Next(-MaxCoord, MaxCoord + 1),
                    y = Rand.Next(-MaxCoord, MaxCoord + 1);

                points.Add(new Vector2D(x, y));
            }

            return points;
        }

        private static void GenerateTransformGroups(int testNumber, Dictionary<string, List<ITransform>> transformGroups, int groupsCount)
        {
            Console.WriteLine("(transform counts:");

            for (int i = 0; i < groupsCount; i++)
            {
                int transformsCount;
                if (testNumber > 5)
                {
                    transformsCount = Rand.Next((MinTransformsPerGroup + MaxTransformsPerGroup) / 2, MaxTransformsPerGroup);
                }
                else
                {
                    transformsCount = Rand.Next(MinTransformsPerGroup, MaxTransformsPerGroup);
                }

                Console.Write(" " + transformsCount);
                InsertRandomTransformsIntoRespectiveGroup(transformGroups, transformsCount, i);
            }

            Console.WriteLine(")");
        }

        private static void InsertRandomTransformsIntoRespectiveGroup(Dictionary<string, List<ITransform>> transformGroups, int transformsCount, int groupInd)
        {
            List<ITransform> currentTransforms = new List<ITransform>();
            StringBuilder currentGroupNameBuilder = new StringBuilder();
            for (int transformInd = 0; transformInd < transformsCount; transformInd++)
            {
                bool transformTypeTranslation = Rand.Next(2) == 0 ? true : false;
                if (transformTypeTranslation)
                {
                    double xOffset = Rand.Next(-MaxOffset, MaxOffset + 1);
                    double yOffset = Rand.Next(-MaxOffset, MaxOffset + 1);

                    currentTransforms.Add(new TranslateTransform(xOffset, yOffset));
                    currentGroupNameBuilder.Append("t" + "(" + xOffset + "," + yOffset + ")");
                }
                else
                {
                    double angle = Rand.Next(0, 360);

                    currentTransforms.Add(new RotateTransform(angle * TaskPI / 180.0));
                }
            }

            string currentGroupName = currentGroupNameBuilder.ToString();
            if (currentGroupName.Length > MaxGroupNameLength - (MaxGroupNameLength.ToString().Length + 1))
            {
                currentGroupName = currentGroupName.Remove(MaxGroupNameLength - 1);
            }

            currentGroupName = currentGroupName + "." + groupInd.ToString().PadLeft(2, 'c');

            transformGroups[currentGroupName] = currentTransforms;
        }
    }
}
