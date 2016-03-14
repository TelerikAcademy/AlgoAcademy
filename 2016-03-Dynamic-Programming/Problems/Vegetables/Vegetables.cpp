#include <iostream>

const int MAX = 10001;
const int MAX_G = 801;
const int M = 10037;

int gardens[MAX];
// rotate two rows of the gardens to achieve O(N) memory instead of O(N^2)
int64_t first [2][MAX_G];
int64_t second [2][MAX_G];

int64_t optimal(int64_t matrix[][MAX_G], int rows, int cols)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= cols; j++)
        {
            std::cin >> matrix[i % 2][j];
            int next = std::max(matrix[(i - 1) % 2][j], matrix[i % 2][j - 1]);
            matrix[i % 2][j] += next;
        }
    }

    return matrix[rows % 2][cols];
}

// runs in O(logN) time => good performance
int quickPow(int n, int p)
{
    if(p == 0)
    {
        return 1;
    }

    if(p % 2 == 1)
    {
        return quickPow(n, p - 1) * n % M;
    }

    int s = quickPow(n, p / 2);

    return s * s % M;
}

// runs in O(N) time -> slow for big N
int slowPow(int n, int p)
{
    int base = 1;

    for(int i = 0; i < p; i++)
    {
        base = n * base % M;
    }

    return base;
}

int main()
{
    // the input has a max of ~ 2 * 800 * 800 numbers, which is a lot of input
    // so it's beneficial to optimize the input stream
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n1, m1;
    std::cin >> n1 >> m1;

    gardens[0] = optimal(first, n1, m1);

    int n2, m2;
    std::cin >> n2 >> m2;
    gardens[1] = optimal(second, n2, m2);

    int index;
    std::cin >> index;

    for(int i = 2; i < index; i++)
    {
        gardens[i] = quickPow(gardens[i - 2], gardens[i - 1]);
    }

    std::cout << gardens[index - 1] << std::endl;

    return 0;
}
