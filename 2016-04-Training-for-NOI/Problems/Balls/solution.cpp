#include <iostream>

int moves[54];
bool memory[100101];

int main()
{
    int n, a, b;
    std::cin >> n;

    for(size_t i = 0; i < n; i++)
    {
        std::cin >> moves[i];
    }

    std::cin >> a >> b;

    for(size_t i = 0; i < b; i++)
    {
        if(!memory[i])
        {
            for(size_t j = 0; j < n; j++)
            {
                memory[i + moves[j]] = true;
            }
        }
    }

    int wins = 0;

    for(size_t i = a; i <= b; i++)
    {
        wins += memory[i];
    }

    std::cout << wins;
}
