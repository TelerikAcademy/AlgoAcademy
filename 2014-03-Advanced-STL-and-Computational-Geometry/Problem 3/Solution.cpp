// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;

	Point(coord_t x = 0, coord_t y = 0)
	{
	    this->x = x;
	    this->y = y;
	}

	static double CrossProduct(const Point &a, const Point &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    Point operator + (const Point &other) const
    {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator - (const Point &other) const
    {
        return Point(this->x - other.x, this->y - other.y);
    }

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

void PrintVector2Container(vector<Point> c)
{
    for(int i=0; i<c.size(); i++)
    {
        cout<<c[i].x<<" "<<c[i].y<<endl;
    }
}

double CalculateSurface(vector<Point> polyPoints)
{
    Point basePoint = polyPoints[0];

    double surface = 0;

    for(int i=1; i<polyPoints.size() - 1; i++)
    {

        Point baseToFirst = polyPoints[i] - basePoint;
        Point baseToSecond = polyPoints[i + 1] - basePoint;

        surface += Point::CrossProduct(baseToFirst, baseToSecond) / 2;
    }


    return abs(surface);
}

int main()
{
    int n;
    cin>>n;

    vector<Point> poly;

    for(int i=0; i<n; i++)
    {
        double x, y;
        cin>>x>>y;

        poly.push_back(Point(x,y));
    }

    PrintVector2Container((convex_hull(poly)));

    cout<<CalculateSurface(convex_hull(poly))<<endl;
}
