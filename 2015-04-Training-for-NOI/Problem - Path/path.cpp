#include<iostream>
using namespace std;
int main()
{
	int v1, v2, t, d;
	cin >> v1 >> v2;
	cin >> t >> d;

	int total = 0;
	for(int i=t; i>0; --i)
	{
		if(v1<v2)
		{
			total += v1;
			v1 += d;
		}
		else
		{
			total += v2;
			v2 += d;
		}
	}

	cout << total << '\n';
}
