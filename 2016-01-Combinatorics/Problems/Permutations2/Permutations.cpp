#include<iostream>
#include<algorithm>

int numbers[21];
long long factorial[21] {1};
bool used[21];

int getId(int number)
{
	return std::count(used + 1, used + number, false);
}

int main()
{
	int n = 0;

	while(std::cin >> numbers[n])
		++n;

	for(int i = 1; i <= n; ++i)
		factorial[i] = i * factorial[i - 1];

	long long k = 1;

	for(int i = 0; i < n; ++i)
	{
		int id = getId(numbers[i]);
		k += factorial[n - 1 - i] * id;
		used[numbers[i]] = true;
	}

	std::cout << k << '\n';
}
