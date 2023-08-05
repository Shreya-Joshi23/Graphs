#include<bits/stdc++.h>
using namespace std;


// int main(){
    //storing in a matrix - Space comlexity-O(n^2)
    // int n,m;
    // cin>>n>>m;

//     int adj[n+1][m+1]={0};

//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }

//     for(int i=0;i<m;i++){
//         for(int j=0;j<m;j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;

// }


//Graph implementation using list

// int main(){

// //Number of nodes  and number of edges
// //Space Complexity - O(2*Number of edges) - Undirected graph
// //Space complexity - O(Number of eddges) - Directed graph

// int n,m;
// cin>>n>>m;
// vector<int>arr[n+1];

// for(int i=0;i<m;i++){
//     int u,v;
//     cin>>u>>v;
//     arr[u].push_back(v);
//     arr[v].push_back(u);
// }

// return 0;

// }

//Weighted graph implementation

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

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;

}
