#include<iostream>
using namespace std;
const int MAXV = 10042;
int A[128][MAXV];
int main()
{
	int v1, v2, t, d;
	cin >> v1 >> v2;
	cin >> t >> d;

	for(int i=0;i<128;++i)
		for(int j=0;j<MAXV;++j)
			A[i][j]=-1;
	A[0][v1] = 0;

	for(int i=0; i<t; ++i)
	{
		for(int j=0; j<4096; ++j)
		{
			if(A[i][j]<0)
				continue;
			for(int k=max(0, j-d); k<=j+d; ++k)
				A[i+1][k] = max(A[i+1][k], A[i][j]+j);
		}
	}

	cout << A[t-1][v2]+v2 << '\n';
}
