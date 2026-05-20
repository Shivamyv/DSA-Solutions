class Solution {
public:
 void dfs  (int node,vector<vector<int>>& isConnected,vector<int>&vis){
    int n=isConnected.size();
    vis[node]=1;
    for(int i=0;i<n;i++){
        if(isConnected[node][i] &&!vis[i]){
            dfs(i,isConnected,vis);

        }
    }


 }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        }
   vector<int>vis(n,0);
   int cnt=0;
   for(int i=0;i<n;i++){
    if(!vis[i]){
        cnt++;
        dfs(i,isConnected,vis);
    }
   }


   return cnt;


    }
};