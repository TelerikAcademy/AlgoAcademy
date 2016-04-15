#include<iostream>
#include<set>

const int MAXN = 300042;
int A[MAXN];

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n, q;
	std::cin >> n >> q;

	for(int i = 0; i < n; ++i)
		std::cin >> A[i];

	std::set<int> break_points;

	for(int i = 1; i < n; ++i)
	{
		if(A[i] <= A[i - 1])
			break_points.insert(i);
	}

	for(int i = 0; i < q; ++i)
	{
		char c;
		int x, y;
		std::cin >> c >> x >> y;

		if(c == '=')
		{
			A[x] = y;

			if(x > 0)
			{
				if(A[x] <= A[x - 1])
					break_points.insert(x);
				else break_points.erase(x);
			}

			if(x < n - 1)
			{
				if(A[x + 1] <= A[x])
					break_points.insert(x + 1);
				else break_points.erase(x + 1);
			}
		}
		else // ?
		{
			// [ x, y ) -> ( x, y )
			auto it = break_points.upper_bound(x);
			std::cout << (it != break_points.end() && *it >= y) << '\n';
		}
	}
}
