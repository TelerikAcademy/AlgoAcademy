#include<iostream>
#include<cmath>
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

Vector2 LineIntersection(Vector2 A1, Vector2 B1, Vector2 A2, Vector2 B2)
{
    Vector2 P = A1;
    Vector2 Q = B2;

    Vector2 u = B1 - A1;
    Vector2 v = B2 - A2;

    double sNominator = v.x * (P.y - Q.y) - v.y * (P.x - Q.x);
    double sDemoninator = u.x * v.y - v.x * u.y;

    double s = sNominator / sDemoninator;

    return P + (u * s);
}

int main()
{
    Vector2 intersect = LineIntersection(Vector2(0, 0),
                                         Vector2(1, 2),
                                         Vector2(1, 5),
                                         Vector2(4, 2)
                                        );

    cout<<intersect.x<<" "<<intersect.y<<endl;


}
