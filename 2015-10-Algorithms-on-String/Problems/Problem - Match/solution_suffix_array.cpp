#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Rank[1<<20];
int index[1<<20];
pair<int, int> Value[1<<20];
int LCP[1<<20];

int main()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);

	string str = A;
	str.push_back(0);
	str += B;
	int N = str.size();

	for(int i=0; i<(int)str.size(); ++i)
		index[i] = i;

	for(int i=0; i<N; ++i)
		Rank[i] = str[i];

	for(int k=0; (1<<k)<N; ++k)
	{
		for(int i=0; i<N; ++i)
			Value[i].first = Rank[i];
		for(int i=(1<<k); i<N; ++i)
			Value[i-(1<<k)].second = Rank[i];
		for(int i=N-(1<<k); i<N; ++i)
			Value[i].second = -1;

		sort(index, index+N, [](int a, int b) {
			return Value[a] < Value[b];
		});
		
		Rank[index[0]] = 0;
		for(int i=1; i<N; ++i)
			Rank[index[i]] = Rank[index[i-1]] + (Value[index[i]] != Value[index[i-1]]);
	}

	for(int len=0, i=0; i<N; ++i)
	{
		int ind = Rank[i];
		if(ind == 0) continue;
		while(str[i + len] == str[index[ind-1] + len])
			++len;
		LCP[ind] = len;
		if(len > 0) --len;
	}

	int ans = 0;
	for(int i=2; i<N; ++i)
		if((index[i-1] < (int)A.size()) ^ (index[i] < (int)A.size()))
			if(ans < LCP[i]) ans = LCP[i];
	cout << ans << '\n';
}
