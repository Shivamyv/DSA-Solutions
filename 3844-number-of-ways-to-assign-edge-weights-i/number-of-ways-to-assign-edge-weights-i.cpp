class Solution {
public:
  long long mod=1e9+7;

    long long maxdepth(int node,vector<vector<int>>&adj,vector<int>&vis){
         long long depth=0;
          vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
          depth=max(depth,1+maxdepth(it,adj,vis)) ;
         
            }
        }
        return depth ;
    }

    long long power(long long a, long long b) {
    long long ans = 1;

    while (b > 0) {
        if (b & 1)
        ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}
  
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
      vector<vector<int>>adj(n+1);
       for(auto it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       long long depthfind=0;
       long long ways=0;
    vector<int>vis(n+1,false);
    
       depthfind=maxdepth(1,adj,vis);

        ways =power(2,depthfind-1);

    
   return ways;
        
    }
};