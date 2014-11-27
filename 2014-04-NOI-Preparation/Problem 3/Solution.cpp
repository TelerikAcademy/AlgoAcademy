#include<iostream>
#include<vector>

using namespace std;

int GetUpBitsInColumn(vector<int> numbers, int columnInd)
{
    int upBitsInCol = 0;
    for(int numInd = 0; numInd < numbers.size(); numInd++)
    {
        int mask = 1;
        mask = mask << columnInd;

        if(numbers[numInd] & mask)
        {
            upBitsInCol++;
        }
    }

    return upBitsInCol;
}

bool IsWinPossibleForCurrentPlayer()
{
    int availableMoves;
    cin>>availableMoves;

    int numRows;
    cin>>numRows;

    int numCols;
    cin>>numCols;

    vector<int> distances;
    for(int row=0; row<numRows; row++)
    {
        int left, right;
        cin>>left>>right;
        int dist = right - left - 1;

        distances.push_back(dist >= 0 ? dist : -dist);
    }

    for(int bitCol = 0; bitCol < 30; bitCol++)
    {
        int x = GetUpBitsInColumn(distances, bitCol);

        if(x % (availableMoves+1) != 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int numGames;
    cin>>numGames;

    for(int i=0; i<numGames; i++)
    {
        bool win = IsWinPossibleForCurrentPlayer();

        if(win)
        {
            cout<<"win"<<endl;
        }
        else
        {
            cout<<"lose"<<endl;
        }
    }
}
