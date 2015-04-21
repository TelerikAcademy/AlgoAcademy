#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

struct sweep{
	int x,y;
	bool add;
};

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin>>n;
	std::vector<sweep> v;
	v.reserve(n*2);
	for(int i=0;i<n;++i)
	{
		int x,y1,y2;
		std::cin>>x>>y1>>y2;
		v.push_back({x,y1,true});
		v.push_back({x,y2,false});
	}
	std::sort(v.begin(), v.end(), [](const sweep &A, const sweep &B){return A.y<B.y;});

	int mindist = 2000000042;
	std::multiset<int> lines;

	for(auto &p:v)
	{
		if(p.add)
		{ // Rewrite me
			auto it = lines.insert(p.x);
			if(it != lines.begin())
			{
				auto tmp = it; --tmp;
				if(*it - *tmp < mindist)
					mindist = *it - *tmp;
			}
			auto tmp = it; ++it;
			if(it != lines.end())
				if(*it - *tmp < mindist)
					mindist = *it - *tmp;
		}
		else lines.erase(lines.find(p.x));
	}

	if(mindist == 2000000042)
		std::cout<<"--\n";
	else std::cout<<mindist<<'\n';
}
