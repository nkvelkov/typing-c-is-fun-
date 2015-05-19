#include "Graph.h"
#include <iostream>

Graph :: Graph()
{
    vector<int> temp;
    adj.push_back(temp);
}

bool Graph:: hasNode(int node)const
{
    for(int i = 0; i < adj.size(); ++i)
    {
        if(adj[i].size() > 0)
        if(node == adj[i][0])
        {
            return true;
        }
    }
    return false;
}

bool Graph:: addNode(int node)
{
    if(hasNode(node))
    {
        return false;
    }
    adj[0].push_back(node);

    vector<int> temp;
    temp.push_back(node);
    adj.push_back(temp);

    return true;
}

bool Graph:: removeNode(int node)
{
    if(!hasNode(node))
    {
        return false;
    }

    for(int i = 0; i < adj.size(); ++i)
    {
        if(adj[i][0] == node)
        {
            adj.erase( adj.begin() + i);
            break;
        }
    }

    for(int i = 0; i < adj.size(); ++i)
    {
        for(int j = 0; j < adj[i].size(); ++j)
        {
            if(adj[i][j] == node)
            {
                adj[i].erase(adj[i].begin() + j);
                break;
            }
        }
    }
    return true;
}

bool Graph:: hasLink(int start, int end)const
{
    for(int j = 0; j < adj.size(); ++j)
    {
        if(adj[j][0] == start)
        for(int i = 0; i < adj[j].size(); ++i)
        {
            if(adj[j][i] == end)
            {
                return true;
            }
        }
    }
    return false;
}

bool Graph:: addLink(int start, int end)
{
    if( hasLink(start, end) )
    {
        return false;
    }

    bool b = addNode(start); addNode(end);
    for(int i = 0; i < adj.size(); ++i)
    {
        if(adj[i][0] == start)
        {
            adj[i].push_back(end);
            break;
        }
    }
    return true;
}

bool Graph:: removeLink(int start, int end)
{
    if(!hasLink(start, end))
    {
        return false;
    }

    for(int i = 0; i < adj.size(); ++i)
    {
        if(adj[i][0] == start)
        {
            for(int j = 0; j < adj[i].size(); ++j)
            {
                if(adj[i][j] == end)
                {
                    adj[i].erase(adj[i].begin() + j);
                    break;
                }
            }
        }
    }

    return true;
}

bool Graph:: isEmpty()const
{
    return adj.size() == 0;
}

vector<int> Graph:: nodes()const
{
    vector<int> ans;
    for(int i = 0 ; i < adj[0].size(); ++i)
    {
        ans.push_back(adj[0][i]);
    }
    return ans;
}

vector<int> Graph:: adjacentNodes(int node)const
{
    vector <int> ans;
    if(hasNode(node))
    for(int i = 0 ; i < adj.size(); ++i)
    {
        if(adj[i][0] == node)
        for(int j = 1; j < adj[i].size(); ++j)
        {
            ans.push_back(adj[i][j]);
        }
    }
    return ans;
}
