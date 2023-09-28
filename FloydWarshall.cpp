#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int V,vector<vector<int>>adj,int src){

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==-1){
                    adj[i][j]=1e9;
                }
            }
        }

        for(int via=0;via<V;via++){
            for(int src=0;src<V;src++){
                for(int des=0;des<V;des++){
                    if((adj[src][via]+adj[via][des])<adj[src][des]){
                        adj[src][des]=adj[src][via]+adj[via][des];
                    }
                }
            }
        }

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1e9){
                    adj[i][j]=-1;
                }
            }
        }

        return adj;

}