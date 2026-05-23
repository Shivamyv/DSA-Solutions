class Solution {
public:
void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    
  
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=1;
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
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol]&& 
            grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});

            }
        }



    }
    


}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
         for(int i = 0; i < m; i++) {

            if(grid[i][0] == 1 && !vis[i][0]) {
                bfs(i, 0, vis, grid);
            }

            if(grid[i][n-1] == 1 && !vis[i][n-1]) {
                bfs(i, n-1, vis, grid);
            }
        }

        // first and last row
        for(int j = 0; j < n; j++) {

            if(grid[0][j] == 1 && !vis[0][j]) {
                bfs(0, j, vis, grid);
            }

            if(grid[m-1][j] == 1 && !vis[m-1][j]) {
                bfs(m-1, j, vis, grid);
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;




    }
};