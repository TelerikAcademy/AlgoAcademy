#include <iostream>
using namespace std;

char canvas[100][100];
int rows;
int cols;

int solve()
{
    int answer = 0;

    for (int i = 0; i < rows; i++)
    {
        bool inRed = false;
        for (int j = 0; j < cols; j++)
        {
            if (canvas[i][j] == 'R' || canvas[i][j] == 'G')
            {
                if (!inRed)
                {
                    answer++;
                    inRed = true;
                }
            }
            else
            {
                inRed = false;
            }
        }
    }

    for (int i = 0; i < cols; i++)
    {
        bool inBlue = false;
        for (int j = 0; j < rows; j++)
        {
            if (canvas[j][i] == 'B' || canvas[j][i] == 'G')
            {
                if (!inBlue)
                {
                    answer++;
                    inBlue = true;
                }
            }
            else
            {
                inBlue = false;
            }
        }
    }

    return answer;
}

int main()
{
    cin >> rows;
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < cols; j++)
        {
            canvas[i][j] = line[j];
        }
    }

    cout << solve();
}
