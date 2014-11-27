#include<map>
#include<iostream>

using namespace std;

int main()
{
    map<long long, long long> sumsByHeight;

    int n;
    cin>>n;

    int maxH = 0;
    int maxW = 0;

    for(int i=0; i < n; i++)
    {
        long long h, w;
        cin>>h>>w;

        int currentSum = (sumsByHeight[h]+=w);

        if(maxW < currentSum)
        {
            maxW = currentSum;
            maxH = h;
        }
    }

    cout<<maxH<<" "<<maxW<<endl;
}
