class Solution {
public:
 int bfs(vector<vector<char>>& maze, vector<int>& entrance){
    int m=maze.size();
    int n=maze[0].size();
    int r=entrance[0];
    int c=entrance[1];
    
    vector<vector<int>>vis(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c},0});
    vis[r][c]=1;
    
   int dr[4]={-1,0,+1,0};
   int dc[4]={0,+1,0,-1};
   while(!q.empty()){
    auto it=q.front();
    int rr=it.first.first;
    int rc=it.first.second;

    int steps=it.second;

    q.pop();
    for(int i=0;i<4;i++){
        int nrow=rr+dr[i];
        int ncol=rc+dc[i];
        
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && maze[nrow][ncol]!='+'){
           if(nrow==0 || nrow==m-1 || ncol==0 || ncol==n-1)
        return steps+1;

             q.push({{nrow,ncol},steps+1});
             vis[nrow][ncol]=1;

        }
   
        
    }

   }

   return -1;

 }



    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
     int m=maze.size();
     int n=maze[0].size();
     return bfs(maze,entrance);

    }
};