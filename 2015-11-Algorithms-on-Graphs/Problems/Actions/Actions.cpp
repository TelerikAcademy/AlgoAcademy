#include<iostream>
#include<vector>
#include<queue>

const int MAXN = 1 << 14;

std::vector<int> A[MAXN];
int depends[MAXN];

int main()
{
	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		A[a].push_back(b);
		++depends[b];
	}

	std::priority_queue<int> q;
	std::vector<int> order;

	for(int i = 0; i < n; ++i)
		if(!depends[i])
			q.push(-i);

	while(!q.empty())
	{
		int x = -q.top(); q.pop();

		order.push_back(x);
		
		for(int y : A[x])
		{
			--depends[y];
			if(!depends[y])
				q.push(-y);
		}
	}

	for(int x : order)
		std::cout << x << '\n';
}
