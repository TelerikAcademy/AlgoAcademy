#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_TOWER_SIZE = 250000;
const int INF = 1000000;

int mem[50][MAX_TOWER_SIZE+1];

int subProblem(const vector<int> &bricks, int K, int D)
{
    if(D>MAX_TOWER_SIZE) // Invalid case,
        return -INF;     // difference is too large

    if(K== bricks.size() )
    {
        if ( D == 0)  //towers have equal sizes:
            return 0; //So it is a valid case with max increment 0
        else
            return -INF ; //invalid case.
    }

    int &res = mem[K][D];
    if(res!=-1)     // memo-ization step
        return res; //

    // ignore this brick:
    int a = subProblem( bricks, K+1, D);

    // place this brick on the larger tower (A):
    int b = subProblem( bricks, K+1, D + bricks[K] );

    // place this brick on the shorter tower:
    int c;
    if ( bricks[K] > D)
        c = D + subProblem( bricks, K+1, bricks[K]-D); //(C)
    else
        c = bricks[K] + subProblem( bricks, K+1, D-bricks[K]); //(B)

    res = max(a, std::max(b,c) ); //pick the largest tower
                                       // size increment.
    return res;

}

int main()
{
    vector<int> bricks;
    memset(mem, -1, sizeof(mem));           // initialize memory

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int current;
        cin >> current;
        bricks.push_back(current);
    }

    int largest = subProblem(bricks, 0, 0);

    if( largest == 0) // for our subproblem, a par of towers
        return -1;    // of size 0 is possible, but the problem
                      // requires us to return -1 in this case.

    cout << largest;
}
