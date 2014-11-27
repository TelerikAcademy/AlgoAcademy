#include <iostream>
using namespace std;

int main(void) {
	int a, b, c, n;
	int result = 0;

	cin >> a >> b >> c >> n;

	for (int k = 0; k < n; k++)
	{
		if (a >= b && a >= c && a >= 1)
		{
			result += a;
			a--;
			continue;
		}
		if (b >= a && b >= c && b >= 1)
		{
			result += b;
			b--;
			continue;
		}
		if (c >= b && c >= a && c >= 1)
		{
			result += c;
			c--;
			continue;
		}
	}

	cout << result;

	return 0;
}
