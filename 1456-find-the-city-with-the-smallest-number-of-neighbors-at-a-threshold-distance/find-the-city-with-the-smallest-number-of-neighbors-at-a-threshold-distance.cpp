class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<pair<int,int>>adj[n];
         
         int city=-1,maxcount=n;
         for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});


         }   
     
      priority_queue<pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>>>pq;
      
       for(int src=0;src<n;src++){
         vector<int>dis(n,1e9);
      pq.push({0,src});
      dis[src]=0;
      while(!pq.empty()){

        auto it=pq.top();
        pq.pop();
        int dist=it.first;
        int node=it.second;
        for(auto it:adj[node]){
            int adjnode=it.first;
            int edgewt=it.second;
            if(dist+edgewt<dis[adjnode]){
              dis[adjnode]=dist+edgewt;
              pq.push({dist+edgewt,adjnode});

            }

        }
      }
      
      int cnt=0;
      for(int i=0;i<n;i++){
        if(i!=src && dis[i]<=distanceThreshold) cnt++;
      }  
       
      if(cnt<=maxcount){
        maxcount=cnt;
        city=src;
      }
       }
    
  

    return city;
    }
};