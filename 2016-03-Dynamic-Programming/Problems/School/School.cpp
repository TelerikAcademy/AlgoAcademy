#include<iostream>
#include<vector>
#include<queue>

const int MAXN = 512;

int maxTime[MAXN];
int parents[MAXN];

std::vector<std::pair<int, int>> A[MAXN];

int main()
{
	std::ios::sync_with_stdio(0);

	int n, m, x, y;
	std::cin >> n >> m >> x >> y;
	--x; --y;

	for(int i = 0; i < m; ++i)
	{
		int a, b, time;
		std::cin >> a >> b >> time;
		--a; --b;
		A[a].push_back({b, time});
	}

	std::queue<int> q;
	q.push(x);

	while(!q.empty())
	{
		int node = q.front(); q.pop();

		for(auto &p : A[node])
		{
			if(parents[p.first] == 0)
				q.push(p.first);
			++parents[p.first];
		}
	}

	q.push(x);

	while(!q.empty())
	{
		int node = q.front(); q.pop();

		for(auto &p : A[node])
		{
			if(maxTime[node] + p.second > maxTime[p.first])
				maxTime[p.first] = maxTime[node] + p.second;

			--parents[p.first];
			if(parents[p.first] == 0)
				q.push(p.first);
		}
	}

	std::cout << maxTime[y] << '\n';
}
