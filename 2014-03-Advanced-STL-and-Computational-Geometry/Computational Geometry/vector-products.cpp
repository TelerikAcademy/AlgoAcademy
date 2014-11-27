#include<iostream>
#include<cmath>

using namespace std;

struct Vector2d
{
    double x, y;

    Vector2d(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    static double CrossProduct(const Vector2d &a, const Vector2d &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    static double DotProduct(const Vector2d &a, const Vector2d &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    static double GetAngleRad(const Vector2d &a, const Vector2d &b)
    {
        return acos(DotProduct(a, b) / (a.Length() * b.Length()));
    }

    double DotProduct(const Vector2d &other) const
    {
        return DotProduct(*this, other);
    }

    Vector2d operator + (const Vector2d &other) const
    {
        return Vector2d(this->x + other.x, this->y + other.y);
    }

    Vector2d& operator += (const Vector2d &other)
    {
        *this = Vector2d(this->x += other.x, this->y += other.y);
        return *this;
    }

    Vector2d operator - (const Vector2d &other) const
    {
        return Vector2d(this->x - other.x, this->y - other.y);
    }

    Vector2d operator * (const double &factor) const
    {
        return Vector2d(this->x * factor, this->y * factor);
    }

    double Length() const
    {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    void Print()
    {
        cout<<"("<<this->x<<", "<<this->y<<")"<<endl;
    }
};

double Radians2Degrees(double rad)
{
    return rad * 180 / M_PI;
}

double Degrees2Radians(double deg)
{
    return deg * M_PI / 180;
}

int main()
{
    Vector2d A (0, 0),
        B (5, 0),
        C (5, 5);

    Vector2d AC = C - A,
        AB = B - A;

    double surface = abs(Vector2d::CrossProduct(AC, AB) / 2);
    cout<<surface<<endl;
}



