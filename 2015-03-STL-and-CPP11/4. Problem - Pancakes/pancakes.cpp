#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	vector<int> orders(n);
	for(int &x:orders) cin >> x;

	sort(orders.begin(), orders.end());

	vector<int> diffs = {orders[0] - 1};
	diffs.resize(n);

	for(unsigned i=1; i<n; ++i)
		diffs[i] = orders[i] - orders[i-1];

	auto mm = minmax_element(begin(diffs), end(diffs));
	cout << orders.back() - 1 << '\n'
		 << *mm.first << '\n'
		 << *mm.second << '\n'
		 << "No!\n";
}
