#include <bits/stdc++.h>
using namespace std;

// Dijakstra algorithm can be implemented using min heap,queue and set data structures
// Time complexity - O(2ElogV)
// used to find minimum distance from source node to every other node
// not implemented in negative weighted graphs

vector<int> dijakstra(int V, vector<vector<int>> adj[], int src)
{
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }
    dist[src] = 0;
    //{dist,node}
    set<pair<int, int>> st;
    st.insert({0, src});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int wt = it.first;
        int node = it.second;
        st.erase(it);
        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int dis = it[1];
            if (dis + wt < dist[adjnode])
            {
                dist[adjnode] = dis + wt;
                st.insert({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}