#include<iostream>

void print(int n, int* numbers, int &k)
{
	--k;
	if(k == 0)
	{
		for(int i = 0; i < n; ++i)
			std::cout << numbers[i];
		std::cout << '\n';
	}
}

void rec(int index, int n, int* numbers, std::string &relations, int &k)
{
	if(k <= 0) return;

	if(index == n)
	{
		print(n, numbers, k);
		return;
	}

	if(index == 0)
	{
		for(int i = 0; i < 10; ++i)
		{
			numbers[0] = i;
			rec(1, n, numbers, relations, k);
		}

		return;
	}

	if(relations[index - 1] == '=')
	{
		numbers[index] = numbers[index - 1];
		rec(index + 1, n, numbers, relations, k);
	}
	else if(relations[index - 1] == '<')
	{
		int r = numbers[index - 1] == 0 ? 10 : numbers[index - 1];
		for(int i = 1; i < r; ++i)
		{
			numbers[index] = i;
			rec(index + 1, n, numbers, relations, k);
		}
	}
	else
	{
		if(numbers[index - 1] == 0)
			return;

		numbers[index] = 0;
		rec(index + 1, n, numbers, relations, k);

		for(int i = numbers[index - 1] + 1; i < 10; ++i)
		{
			numbers[index] = i;
			rec(index + 1, n, numbers, relations, k);
		}
	}
}

int main()
{
	int n, k;
	std::string relations;

	std::cin >> n >> relations >> k;

	int numbers[32];

	rec(0, n, numbers, relations, k);
}
