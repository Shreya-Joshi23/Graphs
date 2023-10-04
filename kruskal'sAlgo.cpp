//Kruskal's Algorithm is used to find minimum spanning tree

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
vector<int>rank,parent,size;

public:
    DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    }

    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]); 
    }

    void unionbyRank(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

int kruskalAlgo(vector<vector<int>>graph[],int V){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++){
    for(auto it:graph[i]){
        int adjNode=it[0];
        int wt=it[1];
        int node=i;
        edges.push_back({wt,{i,adjNode}});
    }
    }

    DisjointSet ds(V);
    int totSum=0;
    sort(edges.begin(),edges.end());

    for(auto it:edges){
        int u=it.second.first;
        int v=it.second.first;
        int wt=it.first;
        if(ds.findUparent(u)!=ds.findUparent(v)){
            totSum+=wt;
            ds.unionbyRank(u,v);
        }
    }
    
    return totSum;

}