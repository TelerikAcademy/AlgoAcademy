#include<iostream>

struct colony {
	int females;
	int males;
	int steps;

	colony()
	{
		females = 0;
		males = 0;
		steps = 0;
	}

	int population()
	{
		return females + males;
	}

	void radiate()
	{
		males -= males / 2;
	}

	void breed()
	{
		int newMice = std::min(females, males) * 2;
		int newMales = newMice / 4;
		int newFemales = newMice - newMales;

		females += newFemales;
		males += newMales;
	}

	void step(char c)
	{
		++steps;

		if(c == '@')
		{
			radiate();
		}
		else
		{
			if(steps % 3 == 0)
				breed();
		}
	}
};

const int MAXPATH = 1 << 14;
colony dp[4][MAXPATH];

int main()
{
	colony beginning;
	std::cin >> beginning.females >> beginning.males;
	int P;
	std::cin >> P;

	std::string path;
	std::cin >> path;

	int minimalSteps = path.size() / 2;

	path = "123" + path;

	dp[0][0] = beginning;
	dp[1][0] = beginning;
	dp[2][0] = beginning;

	int answer = 1 << 30;

	for(unsigned i = 3; i < path.size(); ++i)
	{
		for(unsigned j = 0; j <= i; ++j)
		{
			auto &best = dp[i % 4][j + 1];
			for(unsigned from = i - 3; from < i; ++from)
			{
				colony copy = dp[from % 4][j];
				copy.step(path[i]);
				if(best.population() < copy.population())
					best = copy;
			}
			
			if(best.steps >= minimalSteps
					&& best.population() >= P
					&& answer > best.steps)
			{
				answer = best.steps;
			}
		}

	}

	std::cout << answer << "\n";
}
