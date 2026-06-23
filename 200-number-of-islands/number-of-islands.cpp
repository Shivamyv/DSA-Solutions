class Solution {
public:
  void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
    int m=grid.size();
      int n=grid[0].size();
      queue<pair<int,int>>q;
      q.push({i,j});
      int dr[]={-1,0,+1,0};
      int dc[]={0,+1,0,-1};
      while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]=='1' && 
            !vis[nrow][ncol] ){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
      }


  }

    int numIslands(vector<vector<char>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      int cnt=0;
      vector<vector<int>>vis(m,vector<int>(n,0));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1' && !vis[i][j]){
                
               bfs(i,j,vis,grid);
                cnt++;
               
                 
                }
            }
        }
       
      return cnt;

    }
};