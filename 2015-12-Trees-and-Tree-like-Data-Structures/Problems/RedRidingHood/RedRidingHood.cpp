#include<iostream>
#include<vector>
#include<algorithm>

int money[100042];
int maxmoney[100042];
std::vector<int> A[100042];

void dfs(int x, int prev)
{
	maxmoney[x] += money[x];

	for(int y : A[x])
	{
		if(y == prev)
			continue;
		maxmoney[y] = maxmoney[x];
		dfs(y, x);
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; ++i)
		std::cin >> money[i];
	
	for(int i = 1; i < n; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	dfs(0, -1);
	int d1 = std::max_element(maxmoney, maxmoney + n) - maxmoney;
	std::fill(maxmoney, maxmoney + n, 0);
	dfs(d1, -1);

	std::cout << *std::max_element(maxmoney, maxmoney + n) << '\n';
}
