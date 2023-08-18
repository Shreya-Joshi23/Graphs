class Solution {
  public:
  
  bool detectCycle(int sr,vector<int> adj[],int vis[]){
      queue<pair<int,int>>q;
      q.push({sr,-1});
      vis[sr]=1;
      
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto i:adj[node]){
              if(vis[i]!=1){
                  vis[i]=1;
                  q.push({i,node});
              }else if(parent!=i){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(i,adj,vis))return true;
            }
        }
        return false;
    }
};
