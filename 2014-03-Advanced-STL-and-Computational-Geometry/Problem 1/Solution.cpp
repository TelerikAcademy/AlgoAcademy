#include<iostream>
#include<vector>

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

int main()
{
    int numPulls;
    cin>>numPulls;

    Vector2 totalPull;

    for(int i=0; i<numPulls; i++)
    {
        int pullX, pullY;
        double pullForce;
        cin>>pullX>>pullY>>pullForce;

        Vector2 pull(pullX, pullY);
        pull *= pullForce;

        totalPull += pull;
    }

    cout<<-totalPull.x<<" "<<-totalPull.y<<endl;
}
/*
3
1 1 0.5
2 0 1
0 2 2
*/
