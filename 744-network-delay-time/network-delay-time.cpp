class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<pair<int,int>>adj[n+1];
      for(auto it:times){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
      }
     vector<int>dist(n+1,1e9);
     priority_queue<pair<int,int>,
     vector<pair<int,int>>,
     greater<pair<int,int>>>pq;

     pq.push({0,k});
     dist[k]=0;
     while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
      
        int distnode=it.first;
        int  node=it.second;

         for(auto it:adj[node]){
            int adjnode=it.first;
            int edgewt=it.second;
            if(distnode+edgewt<dist[adjnode]){
                dist[adjnode]=distnode+edgewt;
                pq.push({distnode+edgewt,adjnode});

            }
         }

     }
     int ans=0;
      for(int i=1;i<=n;i++){
        if(dist[i]==1e9) return -1;
        ans=max(ans,dist[i]);
      }
     return ans;

    }
};