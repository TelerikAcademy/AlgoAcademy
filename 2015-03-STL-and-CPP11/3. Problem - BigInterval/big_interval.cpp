#include<iostream>
#include<stack>
using namespace std;

int A[1 << 17];
int from_left[1 << 17];
int from_right[1 << 17];

int main()
{
	int n;
	cin >> n;

	for(int i=0; i<n; ++i)
		cin >> A[i];

	stack<int> s;
	for(int i=0; i<n; ++i)
	{
		while(!s.empty() && A[s.top()] < A[i])
		{
			from_left[i] += from_left[s.top()] + 1;
			s.pop();
		}
		s.push(i);
	}

//	s.clear();		// STL Stack doesn't have .clear() member function ;(
	while(!s.empty()) s.pop();

	for(int i=n-1; i>=0; --i)
	{
		while(!s.empty() && A[s.top()] < A[i])
		{
			from_right[i] += from_right[s.top()] + 1;
			s.pop();
		}
		s.push(i);
	}

	cout << from_left[0] + from_right[0] + 1;
	for(int i=1; i<n; ++i)
		cout << ' ' << from_left[i] + from_right[i] + 1;
	cout << '\n';
}
