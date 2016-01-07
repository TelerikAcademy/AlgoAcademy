#include<iostream>
#include<vector>

const int MAXN = 1024;

std::vector<int> A[MAXN];

std::vector<int> path;
std::vector<int> last;
int level[MAXN];

void dfs(int x)
{
	for(int y : A[x])
	{
		path.push_back(x);
		level[y] = level[x] + 1;
		dfs(y);
	}
	last[x] = path.size();
	path.push_back(x);
}

int rmq[20][MAXN];

void pre_rmq()
{
	int n = path.size();
	int b = 31 - __builtin_clz(n);

	for(int i = 0; i < n; ++i)
		rmq[0][i] = path[i];

	for(int j = 0; j < b; ++j)
	{
		for(int i = 0; i + (1 << j) < n; ++i)
		{
			rmq[j + 1][i] = level[rmq[j][i]] < level[rmq[j][i + (1 << j)]]
								? rmq[j][i] : rmq[j][i + (1 << j)];
		}
	}
}

int query(int a, int b)
{
	int j = 31 - __builtin_clz(b - a);
	return level[rmq[j][a]] < level[rmq[j][b - (1 << j)]]
				? rmq[j][a] : rmq[j][b - (1 << j)];
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a;
		std::cin >> a;
		A[a].push_back(i);
	}

	path.reserve(2 * n);
	last.reserve(2 * n);
	dfs(0);

	pre_rmq();

	int q;
	std::cin >> q;

	for(int i = 0; i < q; ++i)
	{
		int a, b;
		std::cin >> a >> b;

		int l = last[a], r = last[b];
		if(l > r) std::swap(l, r);
		int parent = query(l, ++r);

		if(a == b)
			std::cout << "You are there\n";
		else if(parent == a || parent == b)
			std::cout << "Directly\n";
		else std::cout << "Through " << parent << '\n';
	}
}
