class Solution {
public:
   int dr[4]={-1,0,+1,0};
   int dc[4]={0,+1,0,-1};
  bool check(int safeness, vector<vector<int>>&dist){
    int n=dist.size();
    if(dist[0][0]<safeness) return false;
      vector<vector<int>>vis(n,vector<int>(n,false));
      queue<pair<int,int>>q;
      q.push({0,0});
      vis[0][0]=true;
      while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();
        if(r==n-1 && c==n-1) return true;
        for(int k=0;k<4;k++){
         int nr=r+dr[k];
         int nc=c+dc[k];
         if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc] && dist[nr][nc]>=safeness){
            q.push({nr,nc});
            vis[nr][nc]=true;
         }
        }
      }
    return false;
      
  }


int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]==1){
        q.push({i,j});
        dist[i][j]=0;
            }
            }
        }

         while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first;
        int c=it.second;
        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n  && dist[nrow][ncol]==-1){
                dist[nrow][ncol]=dist[r][c]+1;
                q.push({nrow,ncol});

               
            }
        }
    }
   
     int high=INT_MIN;
     for(int i=0;i<n;i++) {
      high= max(high, *max_element(dist[i].begin(),dist[i].end()));
      }
     int ans=0;
     int low=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid,dist)){
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;
        }
        
    }


              
      return ans;    
      

        
    }
};