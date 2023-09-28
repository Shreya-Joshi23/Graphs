#include <bits/stdc++.h>
using namespace std;

// Bellman ford algorthim - used to find minimum distance from single source node to every other node
// implemented only in  directed graphs
// can be implemented in negative weighted graphs
//Time complexity - O(N*E)(Quadratic)

vector<int> bellmanford(int V, vector<vector<int>> adj, int src)
{

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : adj)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u]!=1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto it : adj)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u]!=1e9 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;

}