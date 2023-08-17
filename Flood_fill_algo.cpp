int n=grid.size();
        int m=grid[0].size();
        
        //{{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        
        int vis[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int maxt=0;
        
        while(!q.empty()){
            
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            
            maxt=max(maxt,t);
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 
                vis[nrow][ncol]==0){
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
       
        return maxt;