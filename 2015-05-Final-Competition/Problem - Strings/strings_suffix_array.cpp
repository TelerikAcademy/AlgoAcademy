#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	std::string s;
	int k;
	std::cin>>s>>k;

	if(k==1)
	{
		std::cout<<s<<'\n';
		return 0;
	}
	
	std::vector<std::pair<int,int>> v(s.size());
	std::vector<int> rank(s.size());
	std::vector<int> suf(s.size());

	for(unsigned i=0;i<s.size();++i)
		rank[i]=s[i];

	for(int j=0;(1u<<j)<s.size();++j)
	{
		for(int i=0;i<(int)s.size();++i)
		{
			v[i]={rank[i], ((i+(1<<j))<(int)s.size()?rank[(i+(1<<j))]:-1)};
			suf[i]=i;
		}

		sort(suf.begin(), suf.end(), [&v] (int L, int R) {return v[L]<v[R];});

		int R=0;
		rank[suf[0]]=0;
		for(unsigned i=1;i<s.size();++i)
		{
			if(v[suf[i-1]]!=v[suf[i]])
				++R;
			rank[suf[i]]=R;
		}
	}
	v.clear();

	std::vector<int> lcp(s.size());
	for(unsigned i=0,len=0;i<s.size();++i)
	{
		if(rank[i]==0)continue;
		int j=suf[rank[i]-1];
		while(s[i+len]==s[j+len])
			++len;
		lcp[rank[i]]=len;
		if(len>0) --len;
	}

	std::vector<int> ind(s.size());
	for(unsigned i=0;i<s.size();++i)
		ind[i]=i;
	std::sort(ind.begin()+1, ind.end(), [&lcp] (int L, int R) {return lcp[L]<lcp[R];});

	std::map<int,int> M={{0,0}, {s.size(),0}};
	int bestlen=-1, bestocc=-1, bestind;
	for(unsigned i=1;i<ind.size();++i)
	{
		auto it=M.insert({ind[i], lcp[ind[i]]}).first;
		if(lcp[ind[i]]==0)
			continue;
		int occ=std::next(it)->first-std::prev(it)->first;
		if(occ<k)
			continue;
		if(lcp[ind[i]]>bestlen)
		{
			bestlen=lcp[ind[i]];
			bestocc=occ;
			bestind=suf[std::next(it)->first-1];
			continue;
		}
		if(lcp[ind[i]]<bestlen)
			continue;
		if(occ>bestocc)
		{
			bestlen=lcp[ind[i]];
			bestocc=occ;
			bestind=suf[std::next(it)->first-1];
			continue;
		}
		if(occ<bestocc)
			continue;
		if(suf[std::next(it)->first-1]<bestind)
		{
			bestlen=lcp[ind[i]];
			bestocc=occ;
			bestind=suf[std::next(it)->first-1];
		}
	}

	if(bestlen<=0) std::cout<<"-1\n";
	else std::cout<<s.substr(bestind, bestlen)<<'\n';
}
