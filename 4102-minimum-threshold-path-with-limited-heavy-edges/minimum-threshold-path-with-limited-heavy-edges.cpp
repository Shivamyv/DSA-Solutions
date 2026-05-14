class Solution {
public:
 bool bfs(int n, vector<vector<int>>& edges, int source, int target, int k,int threshold){
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            int cost=(wt>threshold ? 1:0);
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
         vector<int> dist(n, INT_MAX);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;
    dist[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
      auto [d,node]=pq.top();
      pq.pop();
      if(d>dist[node])continue;
      for(auto it:adj[node]){
        int adjnode=it.first;
        int cost=it.second;
        if(dist[node]+cost<dist[adjnode]){
            dist[adjnode]=dist[node]+cost;
            pq.push({dist[adjnode],adjnode});
        }
      }



    }


      return dist[target]<=k;  

 }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
    
      if(source==target) return 0;
        int low=0,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bfs(n,edges,source,target,k,mid)){
              ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

    return ans;


    }
};