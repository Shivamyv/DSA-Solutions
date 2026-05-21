class Solution {
public:
  vector<vector<int>> bfs(int sr, int sc, int color, vector<vector<int>>&vis,vector<vector<int>>& image){
     int m=image.size();
       int n=image[0].size();
    int incolor=image[sr][sc];
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc]=true;
     image[sr][sc]=color;
    int dr[]={-1,0,+1,0};
    int dc[]={0,+1,0,-1};
   
    while(!q.empty()){
        auto it=q.front();
        int nr=it.first;
        int nc=it.second;
        
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=nr+dr[i];
            int ncol=nc+dc[i];
        
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] &&
           image[nrow][ncol]==incolor){
            image[nrow][ncol]=color;
            q.push({nrow,ncol});
            vis[nrow][ncol]=true;
       
       
        }
    }
    }
    return image;

 }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int m=image.size();
       int n=image[0].size();
       vector<vector<int>>vis(m,vector<int>(n,false));
       return bfs(sr,sc,color,vis,image);
    }
};