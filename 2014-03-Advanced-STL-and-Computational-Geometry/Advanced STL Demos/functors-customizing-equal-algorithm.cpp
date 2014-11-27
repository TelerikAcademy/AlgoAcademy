#include<iostream>
#include<list>
#include<cmath>

using namespace std;

struct EqualEpsilon
{
    double epsilon;

    EqualEpsilon(double eps)
    {
        this->epsilon = eps;
    }

    bool operator ()(double a, double b)
    {
        return abs(a - b) < this->epsilon;
    }
};

int main()
{
    list<double> range1;
    list<double> range2;

    range1.push_back(5);
    range1.push_back(3.14);
    range1.push_back(6.9);


    range2.push_back(5.09);
    range2.push_back(3.145);
    range2.push_back(6.9999);

    cout<<equal(range1.begin(), range1.end(),range2.begin(),
                EqualEpsilon(0.001));
}
