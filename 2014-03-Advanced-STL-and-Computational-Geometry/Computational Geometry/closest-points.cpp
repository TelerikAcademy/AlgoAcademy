#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

#define MAX_DIST 20000000.0

using namespace std;

struct Vector2
{
    double x;
    double y;

    Vector2(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    double Length2() const
    {
        return this->x * this->x + this->y * this->y;
    }

    double Length() const
    {
        return sqrt(this->Length2());
    }

    static double CrossProduct(const Vector2 &a, const Vector2 &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    static double DotProduct(const Vector2 &a, const Vector2 &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    Vector2 operator + (const Vector2 &other) const
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    Vector2 operator - (const Vector2 &other) const
    {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    Vector2 operator += (const Vector2 &other)
    {
        return Vector2(this->x += other.x, this->y += other.y);
    }

    Vector2 operator * (const double &factor) const
    {
        return Vector2(this->x * factor, this->y * factor);
    }

    Vector2 operator *= (const double &factor)
    {
        return Vector2(this->x *= factor, this->y *= factor);
    }
};

struct AxisSorter
{
    bool operator()(Vector2 a, Vector2 b)
    {
        if (a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};



double ClosestDist(vector<Vector2> &points, int first, int last)
{
    int numPoints = last - first + 1;
    if(numPoints < 2)
    {
        return MAX_DIST;
    }
    else
    {
        int leftLast = first + (numPoints/2) - 1;
        int rightFirst = leftLast + 1;

        double leftMin = ClosestDist(points, first, leftLast);
        double rightMin = ClosestDist(points, rightFirst, last);

        double minDist = min(leftMin, rightMin);

        double minDist2 = minDist * minDist;

        double maxCheckX = points[leftLast].x + minDist;
        for(int pLeft = first; pLeft <= leftLast; pLeft++)
        {
            double maxCheckY = points[pLeft].y + minDist;
            double minCheckY = points[pLeft].y - minDist;
            for(int pRight = rightFirst; pRight <= last; pRight++)
            {
                if(points[pRight].x > maxCheckX || points[pRight].y > maxCheckY || points[pRight].y < minCheckY)
                {
                    continue;
                }

                double dist2 = (points[pLeft] - points[pRight]).Length2();
                if(dist2 < minDist2)
                {
                    minDist2 = dist2;
                }
            }
        }

        return min(minDist, sqrt(minDist2));
    }
}

int main()
{
}


















