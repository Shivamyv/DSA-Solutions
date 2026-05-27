class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=grid.size();
      if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
      queue<pair<pair<int,int>,int>>q;
      vector<vector<int>>vis(n,vector<int>(n,0));
      q.push({{0,0},1});
       vis[0][0]=1;
    int dr[]={-1,-1,0,+1,+1,+1,0,-1};
    int dc[]={0,+1,+1,+1,0,-1,-1,-1};

    while(!q.empty()){
          auto it=q.front();
          q.pop();
          int row=it.first.first;
          int col=it.first.second;
          int steps=it.second;
          if(row==n-1 && col==n-1) return steps;

          for(int i=0;i<8;i++){
              int nrow=row+dr[i];
              int ncol=col+dc[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]&& 
        grid[nrow][ncol]==0){
            q.push({{nrow,ncol},steps+1});
            vis[nrow][ncol]=1;

        }

          }
    }
     return -1; 
      
           
    }
};