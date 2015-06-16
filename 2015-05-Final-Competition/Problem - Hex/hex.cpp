#include<iostream>
#include<queue>
using namespace std;

const int SIZE = 19;
const long long MOD = 1000000007;
// Check long long's
struct matrix{
	long long _[SIZE][SIZE];
	inline long long* operator[](int ind) {return _[ind];}
	inline void operator()(matrix &A, matrix &B)
	{
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
			{
				_[i][j]=0;
				for(int k=0;k<SIZE;++k)
					_[i][j]=(_[i][j]+A[i][k]*B[k][j])%MOD;
			}
	}
	inline void operator*=(matrix &m)
	{
		matrix tmp=*this;
		this->operator()(tmp, m);
	}
	inline void operator^=(long long p)
	{
		matrix tmp[2]{*this};
		bool f=p&1;
		for(int t=1;(1<<t)<=p;++t)
		{
			tmp[t&1](tmp[(t^1)&1], tmp[(t^1)&1]);
			if((p>>t)&1)
			{
				if(f) this->operator*=(tmp[t&1]);
				else
				{
					f=true;
					*this=tmp[t&1];
				}
			}
		}
	}
}A, uno;
matrix constA{{
	{0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0},
	{0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,1,1},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0},
}};

int main()
{
	for(int i=0;i<SIZE;++i) uno[i][i]=1;

	int start, end, events;
	long long moves;
	cin>>start>>end>>moves>>events;
	--start; --end;

	priority_queue<pair<long long, int>,
			vector<pair<long long,int>>,
			greater<pair<long long,int>>> q;
	for(;events>0;--events)
	{
		long long t;
		int cell;
		cin>>t>>cell;
		q.push({t, cell-1});
	}
	q.push({moves, -1});

	unsigned unavailible=0;
	long long t=0;
	A=constA;
	while(1)
	{
		auto x=q.top();q.pop();
		if(t<x.first)
		{
			A^=(x.first-t);
			uno*=A;
			t=x.first;
		}
		if(x.second<0) break;
		unavailible ^= (1<<x.second);
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
				if(((unavailible>>i)&1) || ((unavailible>>j)&1))
					A[i][j] = 0;
				else A[i][j] = constA[i][j];
	}

	cout<<uno[start][end]<<'\n';
}
