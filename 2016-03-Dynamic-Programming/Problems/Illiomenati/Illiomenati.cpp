#include <iostream>

const int INF = 1 << 30;
const int MAX_HEIGHT = 129;

int pyramid[MAX_HEIGHT][MAX_HEIGHT][MAX_HEIGHT];

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    size_t height;
    std::cin >> height >> pyramid[0][0][0];

    for (size_t l = 1; l < height; l++)
    {
        for (size_t i = 0; i <= l; i++)
        {
            for (size_t j = 0; j <= l; j++)
            {
                std::cin >> pyramid[l][i][j];
                
                // find the best of all the cells that we can come from
                int c1 = (i > 0 && j > 0) ? pyramid[l - 1][i - 1][j - 1] : -INF;
                int c2 = (i > 0 && j < l) ? pyramid[l - 1][i - 1][j] : -INF;
                int c3 = (i < l && j > 0) ? pyramid[l - 1][i][j - 1] : -INF;
                int c4 = (i < l && j < l) ? pyra2mid[l - 1][i][j] : -INF;

                pyramid[l][i][j] += std::max(std::max(c1, c2), std::max(c3, c4));
            }
        }
    }
    
    // the best answer is in the last level
    int answer = pyramid[height - 1][0][0];
	for(size_t i = 0; i < height; ++i)
	{
		for(size_t j = 0; j < height; ++j)
		{
			if(answer < pyramid[height - 1][i][j])
				answer = pyramid[height - 1][i][j];
		}
	}

    std::cout << answer;
    return 0;
}
