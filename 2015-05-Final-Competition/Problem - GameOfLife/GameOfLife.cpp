#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_ROWS = 150;
const int MAX_COLS = 150;

bool fieldA [MAX_ROWS][MAX_COLS];
bool fieldB [MAX_ROWS][MAX_COLS];

int CountAliveAround (int cellRow, int cellCol, bool countInFieldA)
{
    int numAlive = 0;
    if (countInFieldA)
    {
        for (int row = cellRow-1; row <= cellRow+1; row++)
        {
            for (int col = cellCol-1; col <= cellCol+1; col++)
            {
                if (row != cellRow || col != cellCol) // if we are not on the center cell
                {
                    if (fieldA[row][col] == true)
                    {
                        numAlive++;
                    }
                }
            }
        }
    }
    else
    {
        for (int row = cellRow-1; row <= cellRow+1; row++)
        {
            for (int col = cellCol-1; col <= cellCol+1; col++)
            {
                if (row != cellRow || col != cellCol) // if we are not on the center cell
                {
                    if (fieldB[row][col] == true)
                    {
                        numAlive++;
                    }
                }
            }
        }
    }
    return numAlive;
}

int main()
{
    int numGenerations = 0;
    cin >> numGenerations;
    int numRows, numCols;
    cin>>numRows>>numCols;
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            cin >> fieldA [row][col];
        }
    }

    bool newGenerationInFieldB = true;

    int currentGeneration = 1;
    while (currentGeneration <= numGenerations)
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                int aliveAroundCurrent;
                bool cellWasAlive;
                if (newGenerationInFieldB)
                {
                    aliveAroundCurrent = CountAliveAround(row, col, true);
                    cellWasAlive = fieldA [row][col];
                    if (cellWasAlive)
                    {
                        if (aliveAroundCurrent == 2 || aliveAroundCurrent == 3)
                        {
                            fieldB [row][col] = true;
                        }
                        else
                        {
                            fieldB [row][col] = false;
                        }
                    }
                    else
                    {
                        if (aliveAroundCurrent == 3)
                        {
                            fieldB [row][col] = true;
                        }
                        else
                        {
                            fieldB [row][col] = false;
                        }
                    }
                }
                else
                {
                    aliveAroundCurrent = CountAliveAround(row, col, false);
                    cellWasAlive = fieldB [row][col];
                    if (cellWasAlive)
                    {
                        if (aliveAroundCurrent == 2 || aliveAroundCurrent == 3)
                        {
                            fieldA [row][col] = true;
                        }
                        else
                        {
                            fieldA [row][col] = false;
                        }
                    }
                    else
                    {
                        if (aliveAroundCurrent == 3)
                        {
                            fieldA [row][col] = true;
                        }
                        else
                        {
                            fieldA [row][col] = false;
                        }
                    }
                }
            }
        }
        currentGeneration++;
        newGenerationInFieldB = !newGenerationInFieldB;
    }

    int numAliveInLastGeneration = 0;
    if (newGenerationInFieldB)
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (fieldA[row][col])
                {
                    numAliveInLastGeneration++;
                }
            }
        }
    }

    else
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (fieldB[row][col])
                {
                    numAliveInLastGeneration++;
                }
            }
        }
    }

    cout << numAliveInLastGeneration << endl;
}
