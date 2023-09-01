class Solution {
    private:
    bool check(int start,int V,int color[],vector<int>adj[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    queue<int>q;
	    q.push(0);
	    
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,color,adj)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};