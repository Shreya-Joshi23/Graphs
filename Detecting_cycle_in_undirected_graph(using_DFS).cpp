class Solution {
  
    // Function to detect cycle in an undirected graph.
    private:
    bool dfs(int parent,int node,vector<int>adj[],int vis[]){
        
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(node,it,adj,vis)==true)
                    return true;
            }else if(parent!=it){
                return true;
            }
        }
        return false;
    }
    
    public:
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(-1,i,adj,vis))return true;
            }
        }
        return false;
    }
};