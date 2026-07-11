class Solution {
public:
void dfs(int node, vector<int>&vis, vector<int>adj[], vector<int>&component){
    vis[node]=1;
    component.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
          dfs(it,vis,adj,component);
        }
    }

}

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        int cnt=0;
       
        vector<int>adj[n];
         for(auto it:edges){
            int u=it[0];
            int v=it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
         }
         for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>component;
                dfs(i,vis,adj,component);
               int m=component.size();
               int degreesum=0;
               for(int node:component){
                degreesum+=adj[node].size();

               } 
               int totaledge=degreesum/2;
               if(totaledge==(m*(m-1))/2){
                cnt++;
               }


            }
           
         }
     return cnt;

    }
};