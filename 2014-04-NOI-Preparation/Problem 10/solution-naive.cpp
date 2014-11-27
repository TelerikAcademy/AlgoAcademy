#include <iostream>
using namespace std;
int main()
{
    long long a, b, c, res[10];
    cin >> a >> b;
    for(int k = 0; k < 10; k++) res[k] = 0;
    for(long long i = a; i <= b; i++)
    {
        if (i % 4 == 0 || i % 7 == 0)
        {
            c = i;
            while(c > 0)
            {
                res[c % 10]++;
                c /= 10;
            }
        }
    }
    for(int k = 0; k < 10; k++)
    {
        cout << res[k];
        if (k < 9) cout << " ";
    }
    cout << endl;
}
