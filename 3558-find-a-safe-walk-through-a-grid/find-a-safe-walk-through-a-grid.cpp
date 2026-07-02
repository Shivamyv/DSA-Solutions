class Solution {
public:
   int dr[4]={-1,0,+1,0};
   int dc[4]={0,+1,0,-1};
   bool bfs(vector<vector<int>>&grid,int health){
    int m=grid.size();
     int n=grid[0].size();
   queue<pair<int,pair<int,int>>>q;
   vector<vector<int>>vis(m,vector<int>(n,-1));
   int starthealth=health;
   if(grid[0][0]==1) starthealth--;
   if(starthealth<1) return false;
   q.push({starthealth,{0,0}});
   vis[0][0]=starthealth;
  
   while(!q.empty()){
    auto it=q.front();
    q.pop();
    int reaminghealth=it.first;
    int r=it.second.first;
    int c=it.second.second;

      if(r==m-1 && c==n-1  ) return true;
      
    
      for(int k=0;k<4;k++){
        int nrow=r+dr[k];
        int ncol=c+dc[k];
      

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n  ){
           int newhealth= reaminghealth;
           if(grid[nrow][ncol]==1) newhealth--;
           if(newhealth>=1 && newhealth> vis[nrow][ncol]){
            q.push({newhealth,{nrow,ncol}});
            vis[nrow][ncol]=newhealth;

        }
      }
   }
   }
    
   return false;

   }
  

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
     int m=grid.size();
     int n=grid[0].size();
    return bfs(grid,health);

    }
};