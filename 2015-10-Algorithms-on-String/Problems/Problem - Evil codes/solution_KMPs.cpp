#include<iostream>
#include<string>
using namespace std;

int getIndex(char c)
{
	if(c <= '9')
		return c - '0';
	c |= 'A' ^ 'a';
	return c - 'a' + 10;
}

string pattern[128], code, ans;
int fail[128];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;

	cin >> N;
	for(int k=0; k<N; ++k)
		cin >> pattern[k];
	
	cin >> code; ans = code;
	for(int k=0; k<N; ++k)
	{
		fail[0] = -1; fail[1] = 0;
		for(unsigned i=1; i<pattern[k].size(); ++i)
		{
			for(int j = fail[i-1]; j >= 0; j = fail[j])
				if(getIndex(pattern[k][j]) == getIndex(pattern[k][i]))
				{
					fail[i+1] = j + 1;
					break;
				}
		}
		for(int i=0, j=0; i<(int)code.size(); ++i)
		{
			for(; j>=0; j=fail[j])
				if(getIndex(code[i]) == getIndex(pattern[k][j]))
					break;
			++j;
			if(j == (int)pattern[k].size())
			{
				if(i&1)
					for(int t=i-j+1; t<=i; ++t)
						ans[t] = '@';
				j = fail[j];
			}
		}
	}
	cout << ans << '\n';
}
