#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool adjMatrix[n][n];



    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            char isConnected;
            cin>>isConnected;
            if(isConnected == '1')
            {
                adjMatrix[row][col] = true;
            }
            else
            {
                adjMatrix[row][col] = false;
            }
        }
    }

    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            cout<<adjMatrix[row][col];
        }
        cout<<endl;
    }

    return 0;
}

/*
0101
0011
0000
0000
*/
