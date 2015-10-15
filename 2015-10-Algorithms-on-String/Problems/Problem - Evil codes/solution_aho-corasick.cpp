#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node{
	node *sym[16];
	node *fl;
	int len;
	node()
	{
		for(auto &x:sym)
			x = nullptr;
		fl = nullptr;
		len = 0;
	}
}trie;

int getIndex(char c)
{
	if(c <= '9')
		return c - '0';
	c |= 'A' ^ 'a';
	return c - 'a' + 10;
}

void push(string &s)
{
	node *x = &trie;
	for(char c:s)
	{
		auto &y = x->sym[getIndex(c)];
		if(!y) y = new node;
		y->fl = &trie;
		x = y;
	}
	x->len = s.size();
}

void pre()
{
	queue<node*> q;
	q.push(&trie);

	while(!q.empty())
	{
		auto x = q.front(); q.pop();
		for(int i=0; i<16; ++i)
		{
			if(x->sym[i])
			{
				q.push(x->sym[i]);
				for(auto y=x->fl; y; y=y->fl)
					if(y->sym[i])
					{
						x->sym[i]->fl = y->sym[i];
						break;
					}
			}
			else
			{
				x->sym[i] = &trie;
				for(auto y=x->fl; y; y=y->fl)
					if(y->sym[i])
					{
						x->sym[i] = y->sym[i];
						break;
					}
			}
		}
	}
}

int main()
{
	int N;
	string s;

	cin >> N;
	for(int i=0; i<N; ++i)
	{
		cin >> s;
		push(s);
	}
	
	pre();

	cin >> s;
	auto x = &trie;
	for(unsigned i=0; i<s.size(); ++i)
	{
		x = x->sym[getIndex(s[i])];
		if(i&1)
			for(unsigned j=i+1-x->len; j<=i; ++j)
				s[j] = '@';
	}
	cout << s << '\n';
}
