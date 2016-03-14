#include<iostream>
#include<vector>

int main()
{
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	std::vector<int> A(n);

	for(int i = 0; i < n; ++i)
	{
		std::cin >> A[i];
	}

	std::vector<int> seq;

	for(int i = 0; i < n; ++i)
	{
		auto left = seq.begin();
		auto right = seq.end();

		while(left != right)
		{
			auto middle = left + (right - left) / 2;

			if(*middle < A[i])
				left = middle + 1;
			else right = middle;
		}

		if(left != seq.end())
			*left = A[i];
		else seq.push_back(A[i]);
	}

	std::cout << seq.size() << '\n';
}
