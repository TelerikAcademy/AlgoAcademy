#include<iostream>
#include<utility>

const int MAXN = 2048;

using pii = std::pair<int, int>;
pii A[MAXN][MAXN];

int cards[MAXN];

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; ++i)
	{
		std::cin >> cards[i];
	}
	for(int i = 0; i < n; ++i)
	{
		A[i][i + 1] = {cards[i], 0};
	}

	for(int i = 2; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			A[j - i][j] = A[j - i + 1][j].first < A[j - i][j - 1].first
				? pii(cards[j - i] + A[j - i + 1][j].second, A[j - i + 1][j].first)
				: pii(cards[j - 1] + A[j - i][j - 1].second, A[j - i][j - 1].first);
		}
	}

	std::cout << A[0][n].first << ' ' << A[0][n].second << '\n';
}
