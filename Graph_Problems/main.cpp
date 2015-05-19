#include <iostream>
#include <set>
#include <iomanip>
#include <queue>
#include "Graph.h"
using namespace std;

bool hasOddCycles(const Graph& g, int node, vector<int>& visited, int ctr);
bool isVisited(int node, const vector<int>& visited);

bool isBipartite(const Graph& g)
{
    bool b = false;
    vector<int> nodes = g.nodes();
    for(int i = 0; i < nodes.size() && !b; ++i)
    {
        vector<int> visited;
        b = hasOddCycles(g, nodes[i], visited, 0);
    }

    return !b;
}

bool hasOddCycles(const Graph& g, int node, vector<int>& visited, int ctr)
{
    if(isVisited(node, visited))
    {
        if(ctr % 2 == 1)
            return true;
        if(g.nodes().size() == visited.size())
            return false;
    }else
    {
        visited.push_back(node);
    }

    vector<int> adjNodes = g.adjacentNodes(node);
    for(int i = 0; i < adjNodes.size(); ++i)
    {
        return hasOddCycles(g, adjNodes[i], visited, ctr+1);
    }

    return false;
}

bool isVisited(int node, const vector<int>& visited)
{
    for(int i = 0; i < visited.size(); ++i)
    {
        if(node == visited[i])
            return true;
    }
    return false;
}
// to do
bool isBipartite2(const Graph& g)
{
    static int ctr = 0, newNode;
    set<int> a, b;
    vector<int> nodes = g.nodes();
    queue<int> q;

    for(int i = 0 ; i < nodes.size(); ++i)
    {
        //conditions missing
        q.push(nodes[i]);
        ++ctr;
        while(!q.empty())
        {
            int cur = q.front();
            vector<int> adjNodes = g.adjacentNodes(cur);
            q.pop();

            if(ctr % 2 == 0)
            {
                a.insert(cur);
                for(int j = 0; j < adjNodes.size(); ++j)
                {
                    newNode = adjNodes[j];
                    b.insert(adjNodes[j]);
                    q.push(newNode);
                }
            }else
            {
                b.insert(cur);
                for(int j = 0; j < adjNodes.size(); ++j)
                {
                    newNode = adjNodes[j];
                    a.insert(adjNodes[j]);
                    q.push(newNode);
                }
            }
        }
    }
}

int main()
{
    Graph G;

    G.addNode(1);
    G.addNode(2);
    G.addNode(3);
    G.addNode(4);
    G.addLink(1, 2);
    G.addLink(2, 3);
    //G.addLink(3, 1);
    G.addLink(3, 4);
    G.addLink(4, 1);

    cout << boolalpha << isBipartite(G) << endl;

    return 0;
}
