
//BRIDGE - An edge on removal divides the graph into two or more components
//TIME COMPLEXITY - O(V+2E)
//SPACE COMPLEXITY - O(3N)+O(V+2E)

#include<bits/stdc++.h>
using namespace std;

int timer=1;
void dfs(int node,int parent,vector<int>&visited,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges){
    visited[node]=1;
    tin[node]=low[node]=timer;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(visited[it]==0){
            dfs(it,node,visited,adj,tin,low,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                bridges.push_back({it,node});
            }
        }else{
            low[node]=min(low[node],low[it]);
        }
    }
}

vector<vector<int>>criticalConnections(int n,vector<vector<int>>&connections){

    vector<int>edges[n];

    for(auto it:connections){
        edges[it[0]].push_back(it[1]);
        edges[it[1]].push_back(it[0]);
    }

    vector<int>visited(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>>bridges;
    dfs(0,-1,visited,edges,tin,low,bridges);
    return bridges;

}