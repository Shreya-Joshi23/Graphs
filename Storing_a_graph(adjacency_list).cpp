#include<bits/stdc++.h>
using namespace std;

//Graph implementation using list

int main(){

//Number of nodes  and number of edges
//Space Complexity - O(2*Number of edges) - Undirected graph
//Space complexity - O(Number of eddges) - Directed graph

int n,m;
cin>>n>>m;
vector<int>arr[n+1];

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    arr[u].push_back(v);
    arr[v].push_back(u);        //UNDIRECTED GRAPH
}

return 0;

}