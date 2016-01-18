#include<iostream>

long long factorial[21] {1};
bool used[21];

int getUnused(int id)
{
	int index = 0;
	while(true)
	{
		do ++index;
		while(used[index]);

		if(id == 0)
			return index;
		--id;
	}
}

int main()
{
	int n;
	long long k;

	std::cin >> n >> k;

	for(int i = 1; i <= n; ++i)
		factorial[i] = i * factorial[i - 1];

	--k;
	for(int i = 0; i < n; ++i)
	{
		int id = k / factorial[n - 1 - i];
		k %= factorial[n - 1 - i];

		if(i > 0) std::cout << ' ';
		int number = getUnused(id);
		std::cout << number;
		used[number] = true;
	}

	std::cout << '\n';
}
