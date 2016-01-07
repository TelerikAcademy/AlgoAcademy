#include<iostream>
#include<vector>
#include<utility>
#include<queue>

const int MAXN = 1 << 14;

std::vector<std::pair<int, int>> A[MAXN];
bool used[MAXN];

int main()
{
	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		int height;
		std::cin >> a >> b >> height;
		--a; --b;
		A[a].push_back({b, height});
		A[b].push_back({a, height});
	}

	int maxheight = 2e9;

	std::priority_queue<std::pair<int, int>> q;
	q.push({maxheight, 0});
	while(!q.empty())
	{
		auto p = q.top(); q.pop();
		if(used[p.second])
			continue;
		if(maxheight > p.first)
			maxheight = p.first;

		used[p.second] = true;
		for(auto &x : A[p.second])
		{
			if(used[x.first])
				continue;
			q.push({x.second, x.first});
		}
	}

	std::cout << maxheight << '\n';
}
