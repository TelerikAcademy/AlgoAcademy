#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

vector <vector <int> > neighbors;
vector <bool> visited;

void MarkWithBFS(int start)
{
    queue<int> toVisit = queue<int>();
    toVisit.push(start);
    visited[start] = true;

    while(!toVisit.empty())
    {
        int current = toVisit.front();
        toVisit.pop();

        vector<int> currentNeighbor = neighbors[current];
        int currentNeighborSize = currentNeighbor.size();

        for(int nextInd = 0; nextInd < currentNeighborSize; nextInd++)
        {
            int next = currentNeighbor[nextInd];
            if(!visited[next])
            {
                toVisit.push(next);
                visited[next] = true;
            }
        }
    }
}

int Solve()
{
    int vertices;
    cin>>vertices;

    neighbors = vector<vector <int> >();
    visited = vector<bool>();

    neighbors.reserve(vertices);
    visited.reserve(vertices);

    for(int i=0; i<vertices; i++)
    {
        neighbors.push_back(vector<int>());

        string line;
        cin>>line;
        for(int j=0; j<vertices; j++)
        {
            if(line[j] == '1')
            {
                neighbors[i].push_back(j);
            }
        }

        visited.push_back(false);
    }

    int componentsCount = 0;
    for(int i=0; i<visited.size(); i++)
    {
        if(!visited[i])
        {
            componentsCount++;
            MarkWithBFS(i);
        }
    }

    return componentsCount;
}

int main()
{
    int numTests;
    cin>>numTests;
    for(int i=0; i<numTests; i++)
    {
        cout << Solve() << endl;
    }

}
/*
3
2
01
10
5
01100
10100
11000
00001
00010
6
010000
101000
010100
001000
000001
000010
*/
