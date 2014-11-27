#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, first, second;
    cin>>N>>first>>second;

    vector<int> array;
    int variable;

    for(int i = 0; i < N; i++)
    {
        cin>>variable;
        array.push_back(variable);
    }

    sort(array.begin() + first, array.begin() + (second + 1));

    for(int i = 0; i < N; i++)
    {
        cout<<array.at(i)<<" ";
    }
}
