#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
	cin>>n;

    double sumX = 0, sumY = 0;
    for(int i=0; i<n; i++)
    {
        double currX, currY;

		cin>>currX>>currY;

        sumX += currX;
        sumY += currY;
    }

	cout<<fixed<<setprecision(2)
		<<sumX/n<<' '
		<<sumY/n<<'\n';
}
