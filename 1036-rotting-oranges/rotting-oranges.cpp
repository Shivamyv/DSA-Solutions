class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
   
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({0,{i,j}});
                vis[i][j]=2;
          
            }
        }
    }
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    int time=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int tm=it.first;
        int newi=it.second.first;
        int newj=it.second.second;
        time=max(time,tm);
        for(int i=0;i<4;i++){
            int nrow=newi+dr[i];
            int ncol=newj+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            grid[nrow][ncol]==1){
                q.push({tm+1,{nrow,ncol}});
                vis[nrow][ncol]=2;
            }
        }
    }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]!=2) return -1;
        }
    }   
    
    return time; 

    }
};