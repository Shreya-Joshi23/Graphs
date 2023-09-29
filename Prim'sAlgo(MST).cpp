//Prim's algorithm is used to find minimum spanning tree

#include<bits/stdc++.h>
using namespace std;

long long primalgo(int V,vector<vector<int>>graph[]){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>visited(V,0);

    pq.push({0,0});
    long long sum=0;

    while(!pq.empty()){
        auto it=pq.top();
        int wt=it.first;
        int node=it.second;
        pq.pop();

        if(visited[node]==1)continue;
        sum+=wt;
        visited[node]=1;
        for(auto it:graph[node]){
            int adjwt=it[0];
            int adjnode=it[1];
            if(visited[adjnode]==0)
            pq.push({adjwt,adjnode});
        }

    }

    return sum;

}