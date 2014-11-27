#include<iostream>
#include<vector>
#include<cmath>

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

    static double CrossProduct(const Vector2 &a, const Vector2 &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    static double DotProduct(const Vector2 &a, const Vector2 &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    Vector2 operator + (const Vector2 &other)
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    Vector2 operator - (const Vector2 &other)
    {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    Vector2 operator += (const Vector2 &other)
    {
        return Vector2(this->x += other.x, this->y += other.y);
    }

    Vector2 operator * (const double &factor)
    {
        return Vector2(this->x * factor, this->y * factor);
    }

    Vector2 operator *= (const double &factor)
    {
        return Vector2(this->x *= factor, this->y *= factor);
    }
};

double CalculateSurface(vector<Vector2> polyPoints)
{
    Vector2 basePoint = polyPoints[0];

    double surface = 0;

    for(int i=1; i<polyPoints.size() - 1; i++)
    {

        Vector2 baseToFirst = polyPoints[i] - basePoint;
        Vector2 baseToSecond = polyPoints[i + 1] - basePoint;

        surface += Vector2::CrossProduct(baseToFirst, baseToSecond) / 2;
    }


    return abs(surface);
}

void InputPoly(int numPolyPoints, vector<Vector2> &poly)
{
    for(int i=0; i<numPolyPoints; i++)
    {
        double x, y;
        cin>>x>>y;

        poly.push_back(Vector2(x, y));
    }
}

int main()
{
    int numFirstPoints;
    cin>>numFirstPoints;

    vector<Vector2> firstPoly;
    InputPoly(numFirstPoints, firstPoly);

    int numSecondPoints;
    cin>>numSecondPoints;

    vector<Vector2> secondPoly;
    InputPoly(numSecondPoints, secondPoly);

    //cout<<a<<" "<<b<<endl;

    double surfaceDiff = CalculateSurface(firstPoly) - CalculateSurface(secondPoly);
    //cout<<a - b<<endl;
    cout<< abs(surfaceDiff) <<endl;
}
/*
3
0 0
1 0
1 1
4
-1 0
0 0
0 1
-1 1
*/
