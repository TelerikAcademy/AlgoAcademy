#include <iostream>

const int MAX_H = 1 << 10;
const int MAX_K = 1 << 10;
const int MAX_N = 1 << 10;

int memory[2][MAX_H][MAX_K];
int hours[MAX_N];
int money[MAX_N];

int main()
{
    /*
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    */

    int n, h, k;
    std::cin >> n >> h >> k;

    for(int i = 0; i < n; i++)
    {
        std::cin >> money[i];
    }

    for(int i = 0; i < n; i++)
    {
        std::cin >> hours[i];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= h; j++)
        {
            for(int g = 0; g <= k; g++)
            {
                if(i == 0 || j == 0 || g == 0)
                {
                    memory[i % 2][j][g] = 0;
                }
                else if(hours[i - 1] > j)
                {
                    memory[i % 2][j][g] = memory[(i - 1) % 2][j][g];
                }
                else
                {
                    memory[i % 2][j][g] = std::max(money[i - 1] + memory[(i - 1) % 2][j - hours[i - 1]][g - 1], memory[(i - 1) % 2][j][g]);
                }
            }
        }
    }

    std::cout << memory[n % 2][h][k] << std::endl;
}
