#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int a;
    int b;
    int cost;

    bool operator < (const Edge &other) const
    {
        if (cost < other.cost)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int cities;
    int paths;
    cin >> cities >> paths;

    vector<Edge> edges;

    for (int i = 0; i < paths; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        Edge current;
        current.a = first;
        current.b = second;
        current.cost = third;
        edges.push_back(current);
    }

    sort(edges.begin(), edges.end());

    int minCost = 0;

    int color[1000];
    for (int i = 0; i < cities; ++i)
        color[i] = i;

    for (int i = 0; i < edges.size(); ++i)
    {
        Edge e = edges[i];
        // vertices of the edge are not in the same component
        if (color[e.a] != color[e.b])
        {
            minCost += e.cost;
            // recolor the component
            int oldColor = color[e.b];
            for (int j = 0; j < cities; ++j)
                if (color[j] == oldColor)
                    color[j] = color[e.a];
        }
    }

    cout << minCost;
}
