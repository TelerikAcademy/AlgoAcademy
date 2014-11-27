#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double GetDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double MyAbs(double n)
{
    return n > 0 ? n : -n;
}

int main()
{
    double x1, y1, x2, y2, radius;

    cin>>x1>>y1>>x2>>y2>>radius;

    printf("%.2f", abs(asin(radius/GetDistance(x1, y1, x2, y2))*180/M_PI));
}
