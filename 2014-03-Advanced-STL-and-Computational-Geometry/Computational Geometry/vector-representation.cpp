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

    double Length()
    {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    void Print()
    {
        cout<<"("<<this->x<<", "<<this->y<<")"<<endl;
    }
};

int main()
{
    Vector2d a(1, 1),
        b(3, -2);

    a += b;
    a.Print();

    cout<<a.Length()<<endl;
}
