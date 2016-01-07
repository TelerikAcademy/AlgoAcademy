#include<iostream>
#include<set>
#include<cassert>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	std::set<int64_t> numbers;
	std::multiset<uint64_t> diffs;

	for(int i = 0; i < n; ++i)
	{
		int64_t number;
		std::cin >> number;

		auto p = numbers.insert(number);
		auto pr = p.first != numbers.begin() ? std::prev(p.first) : numbers.end();
		auto nt = std::next(p.first);

		if(p.second) // this is a new number
		{
			if(pr != numbers.end()) diffs.insert(*p.first - *pr);
			if(nt != numbers.end()) diffs.insert(*nt - *p.first);
			if(pr != numbers.end() && nt != numbers.end())
				diffs.erase(diffs.find(*nt - *pr));
		}
		else // remove the number
		{
			if(pr != numbers.end()) diffs.erase(diffs.find(*p.first - *pr));
			if(nt != numbers.end()) diffs.erase(diffs.find(*nt - *p.first));
			if(pr != numbers.end() && nt != numbers.end())
				diffs.insert(*nt - *pr);

			numbers.erase(p.first);
		}

		if(!diffs.empty())
			std::cout << *diffs.begin() << '\n';
		else if(numbers.empty())
			std::cout << "There are no numbers\n";
		else std::cout << "There is only one number\n";
	}
}
