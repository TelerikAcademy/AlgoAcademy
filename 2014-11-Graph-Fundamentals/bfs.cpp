#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<queue>
using namespace std;

struct Edge
{
    int from;
    int to;

    Edge(int from, int to)
    {
        this->from = from;
        this->to = to;
    }
};

void BreadthFirstSearch(vector < vector<int> > adjList, int start)
{
    bool * visited = new bool[adjList.size()];
    for(int i=0; i<adjList.size(); i++)
    {
        visited[i] = false;
    }

    queue<int> toVisit;
    toVisit.push(start);
    visited[start] = true;

    while(!toVisit.empty())
    {
        int current = toVisit.front();
        toVisit.pop();
        cout<<"visiting "<<current<<endl;

        vector<int> adj = adjList[current];

        for(int i=0; i < adj.size(); i++)
        {
            int nodeToEnqueue = adj[i];
            if(!visited[nodeToEnqueue])
            {
                toVisit.push(adj[i]);
                visited[nodeToEnqueue] = true;
            }
        }
    }
}

int main()
{
    vector < vector<int> > adjList;

    int numEdges;
    cin>>numEdges;

    vector<Edge> edges;
    for(int i=0; i<numEdges; i++)
    {
        int from, to;
        cin>>from>>to;

        edges.push_back(Edge(from, to));
    }

    for(int i=0; i<numEdges; i++)
    {
        Edge current = edges[i];
        if(adjList.size() <= current.from)
        {
            adjList.resize(current.from + 1);
        }

        if(adjList.size() <= current.to)
        {
            adjList.resize(current.to + 1);
        }

        adjList[current.from].push_back(current.to);
        adjList[current.to].push_back(current.from);
    }

    BreadthFirstSearch(adjList, 0);
}
/*
6
0 1
0 3
1 2
1 3
3 4
3 5
*/
