#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>

using namespace std;

class Graph
{
public:
    Graph();
    bool addNode(int);
    bool removeNode(int);
    bool addLink(int, int);
    bool removeLink(int, int);
    bool isEmpty()const;

    vector<int> nodes()const;
    vector<int> adjacentNodes(int)const;
    bool hasNode(int)const;
    bool hasLink(int, int)const;

private:
    vector< vector<int> > adj;
};
#endif // GRAPH_H_INCLUDED
