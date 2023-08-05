#include<bits/stdc++.h>
using namespace std;

int main(){
    // storing in a matrix - Space comlexity-O(n^2)
    //n-Number of nodes,m-Number of edges
    int n,m;
    cin>>n>>m;

    int adj[n+1][m+1]={0};

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    return 0;

}





