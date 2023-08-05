//Weighted graph implementation
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Input number of nodes and edges";
    cin>>n>>m;  

    int matrix[n+1][m+1]={0};

    for(int i=0;i<m;i++){
        int u,v,wt;
        cout<<"Input the edge end nodes and weight of that edge";
        cin>>u>>v>>wt;
        matrix[u][v]=wt;
        matrix[v][u]=wt;
    }

    return 0;

}