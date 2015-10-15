#include<iostream>
using namespace std;

int A[256];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int c;
		cin>>c;
		++A[c];
	}
	A[(int)'x'] = 0;
	for(int i=0; i<26; ++i)
	{
		for(int j=0; j<A['A'+i]; ++j)
			cout<<(char)('A'+i);
		for(int j=0; j<A['a'+i]; ++j)
			cout<<(char)('a'+i);
	}
	for(int i=1; i<10; ++i)
		for(int j=0; j<A['0'+i]; ++j)
			cout<<(char)('0'+i);
	for(int j=0; j<A[(int)'0']; ++j)
		cout<<'0';
	cout<<'\n';
}
