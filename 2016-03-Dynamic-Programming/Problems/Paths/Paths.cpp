#include<iostream>
#include<algorithm>

const int MAXSIZE = 3042;

int A[MAXSIZE][MAXSIZE];

int main()
{
	std::ios::sync_with_stdio(0);

	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			std::cin >> A[i][j];
		}

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(i % 2 == 1)
			{
				if(j == 0)
					A[i][j] += A[i - 1][j];
				else A[i][j] += std::min(A[i - 1][j - 1], A[i - 1][j]);
			}
			else
			{
				if(j == m - 1)
					A[i][j] += A[i - 1][j];
				else A[i][j] += std::min(A[i - 1][j], A[i - 1][j + 1]);
			}
		}
	}

	std::cout << *std::min_element(A[n - 1], A[n - 1] + m) << '\n';
}
