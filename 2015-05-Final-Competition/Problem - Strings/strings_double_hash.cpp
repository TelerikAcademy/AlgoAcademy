#include<iostream>
#include<string>
#include<map>
#include<tuple>

uint64_t pow1[1<<20]{1};
uint64_t pow2[1<<20]{1};
struct dhash{
	const static uint64_t BASE1=41, MOD1=1000000007;
	const static uint64_t BASE2=37, MOD2=1000000033;
	uint64_t hash1=0, hash2=0;
	
	inline bool operator<(const dhash &other)
	const {
		if(hash1==other.hash1)
			return hash2<other.hash2;
		return hash1<other.hash1;
	}
	inline void add(char c)
	{
		c-='a'-1;
		hash1=(hash1*BASE1+c)%MOD1;
		hash2=(hash2*BASE2+c)%MOD2;
	}
	inline void del(char c, int n)
	{
		c-='a'-1;
		hash1=(hash1+MOD1-pow1[n]*c%MOD1)%MOD1;
		hash2=(hash2+MOD2-pow2[n]*c%MOD2)%MOD2;
	}
};

std::string s;

inline std::pair<int,int> find(unsigned n)
{
	std::map<dhash, std::pair<int,int>> M;

	dhash rolling_hash;
	for(unsigned i=0;i<n;++i)
		rolling_hash.add(s[i]);

	M[rolling_hash]={1,0};

	for(unsigned i=n;i<s.size();++i)
	{
		rolling_hash.add(s[i]);
		rolling_hash.del(s[i-n], n);

		auto p=M.insert({rolling_hash, {1, i-n+1}});
		if(!p.second)
			++p.first->second.first;
	}

	std::pair<int,int> r(-1, -1);
	for(auto &p:M)
	{
		if(p.second.first>r.first)
			r=p.second;
		else if(p.second.first==r.first && p.second.second<r.second)
			r=p.second;
	}
	return r;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int k;
	std::cin>>s>>k;

	for(unsigned i=0;i<s.size();++i)
	{
		pow1[i+1]=pow1[i]*dhash::BASE1%dhash::MOD1;
		pow2[i+1]=pow2[i]*dhash::BASE2%dhash::MOD2;
	}

	unsigned l=1, r=s.size()+1;
	while(l<r)
	{
		unsigned m=(l+r)/2;
		if(find(m).first<k)
			r=m;
		else l=m+1;
	}

	if(r==1) std::cout<<"-1\n";
	else
	{
		auto p=find(--r);
		std::cout<<s.substr(p.second, r)<<'\n';
	}
}
