#include<iostream>

const int MOD = 1000000007;

int n, A[16][1<<16];

inline bool check(int i, int j)
{
	for(int k=1; k<n; ++k)
	{
		int a = i&3, b = j&3;
		if((a==0 && b==0) || (a==3 && b==3))
			return false;
		i >>= 1; j >>= 1;
	}
	return true;
}

int main()
{
	std::cin >> n;
	for(int i=0; i<(1<<n); ++i)
		A[1][i] = 1;
	for(int r=1; r<n; ++r)
		for(int i=0; i<(1<<n); ++i)
			for(int j=0; j<(1<<n); ++j)
				if(check(i,j))
					A[r+1][j] = (A[r+1][j] + A[r][i]) % MOD;
	int total = 0;
	for(int i=0; i<(1<<n); ++i)
		total = (total + A[n][i]) % MOD;

	std::cout << total << '\n';
}
