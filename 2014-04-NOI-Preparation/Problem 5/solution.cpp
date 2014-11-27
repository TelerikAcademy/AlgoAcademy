#include <iostream>
#define MAXN 256
using namespace std;
bool graph[MAXN][MAXN];
bool isNode[MAXN];
bool used[MAXN];
int main()
{
    string line, answer = "";
    int N;
    cin >> N;

    // Build graph
    for(int i = 0; i < N; i++)
    {
        cin >> line;
        isNode[line[0]] = true;
        for(int j = 1; j < line.length(); j++)
        {
            isNode[line[j]] = true;
            graph[line[j]][line[j-1]] = true;
        }
    }

    // Topological sort
    while(true)
    {
        bool removed = false;

        for(int i = 0; i < MAXN; i++)
        {
            if (isNode[i] && !used[i])
            {
                // Has precedence (i)?
                bool hasPrecedence = false;
                for(int j = 0; j < MAXN; j++)
                {
                    if (graph[i][j])
                    {
                        hasPrecedence = true;
                        break;
                    }
                }

                if (!hasPrecedence)
                {
                    answer += (char)i;
                    for(int j = 0; j < MAXN; j++)
                    {
                        graph[i][j] = false;
                        graph[j][i] = false;
                    }

                    used[i] = true;
                    removed = true;
                    break;
                }
            }
        }

        if (!removed)
        {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
