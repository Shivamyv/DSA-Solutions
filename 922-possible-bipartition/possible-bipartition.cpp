class Solution {
public:
 bool bfs(int node,vector<vector<int>>&adj, vector<int>&vis){

    queue<int>q;
    q.push(node);
    vis[node]=0;
    while(!q.empty()){
        auto nodes=q.front();
        q.pop();
       for(auto it:adj[nodes]){
        if(vis[it]==-1){
           vis[it]=1-vis[nodes];
           q.push(it);
        }
       else if(vis[it]==vis[nodes]) return false;
       } 


    }

   return true;

 }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       int m=dislikes.size();
        
       vector<int>vis(n+1,-1);
        vector<vector<int>>adj(n+1);

      for(int i=0;i<m;i++){
         int u=dislikes[i][0];
         int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      
      for(int i=1;i<=n;i++){
       
            if(vis[i]==-1){
         if (!bfs(i,adj,vis)){

          return false;
         }
             
            }
        }
    
      
        return true;

    }
};