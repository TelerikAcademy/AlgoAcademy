#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int N;
    cin >> N;

    bool hasParent[N+1];
    memset(hasParent, false, N+1);
    int from, to;
    for (int i = 0; i < N; i++)
    {
        cin >> from >> to;
        hasParent[to] = true;
    }

    bool rootFound = false;
    for (int i = 0; i <= N; i++)
    {
        if (!hasParent[i])
        {
            cout << i << endl;
            rootFound = true;
        }
    }

    if (!rootFound)
    {
        cout << "No root found!";
    }

    return 0;
}
