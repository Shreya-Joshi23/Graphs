#include <bits/stdc++.h> 


void dfs(int node,vector<int>&visited,stack<int>&st,vector<int>adj[]){
    visited[node]=1;
    
    for(auto it:adj[node]){
        if(visited[it]==0){
            dfs(it,visited,st,adj);
        }
    }    
    
    st.push(node);
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //using dfs

    vector<int>adj[v];

    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }

    stack<int>st;
    vector<int>visited(v,0);
    
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs(i,visited,st,adj);
        }
    }

    vector<int>topo;
    while(!st.empty()){
        int node=st.top();
        topo.push_back(node);
        st.pop();
    }

    return topo;
    
}