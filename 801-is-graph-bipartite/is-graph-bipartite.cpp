class Solution {
public:
 bool bfs(int start,vector<int>&vis,vector<vector<int>>& graph){

       queue<int>q;
       q.push(start);
       vis[start]=0;
       while(!q.empty()){
        int nodes=q.front();
        q.pop();
        for(auto it:graph[nodes]){
            if(vis[it]==-1 ){
                vis[it]=1-vis[nodes];
                q.push(it);
                
            }
            else if(vis[it]==vis[nodes]) return false;
        }
       }
       return true;


 }


    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
      
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
               if(!bfs(i,vis,graph)) return false;
            }
        }

    return true;

    }
};