#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
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

    for(int node=0; node < adjList.size(); node++)
    {
        cout<<"node "<<node<<" with neighbors:"<<endl;
        for(int i=0; i<adjList[node].size(); i++)
        {
            cout<<adjList[node][i]<<" ";
        }
        cout<<endl;
        //copy(adjList[node].begin(), adjList[node].end(),
        //     ostream_iterator<int>(cout, " "));
    }
}
///1 3
///1 2
///3 1
