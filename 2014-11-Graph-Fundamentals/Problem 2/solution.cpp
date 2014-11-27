#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int N;
    cin >> N;

    bool isParent[N+1];
    memset(isParent, false, N+1);
    int from, to;
    int parents = 0, all = N + 1;
    for (int i = 0; i < N; i++)
    {
        cin >> from >> to;
        if (!isParent[from])
        {
            isParent[from] = true;
            parents++;
        }
    }

    cout << all - parents << endl;

    for (int i = 0; i <= N; i++)
    {
        if (!isParent[i])
        {
            cout << i << endl;
        }
    }

    return 0;
}
