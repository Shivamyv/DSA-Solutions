class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<pair<int,int>>adj[n];
      for(auto it:flights){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
      }
      vector<int>dist(n,1e9);
      priority_queue<pair<int,pair<int,int>>,
      vector<pair<int,pair<int,int>>>,
      greater<pair<int,pair<int,int>>>>pq;
      pq.push({0,{0,src}});
      dist[src]=0;
    
      while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int stops=it.first;
         int distnode=it.second.first;
         int node=it.second.second;

        
         if(stops>k) continue;

         

         for(auto it:adj[node]){
             int adjnode=it.first;
            int edgewt=it.second;
            if(distnode+edgewt<dist[adjnode]&& stops<=k){
                dist[adjnode]=distnode+edgewt;
                pq.push({stops+1,{distnode+edgewt,adjnode}});
                


            }
            
         }
         


      }
     if(dist[dst]==1e9) return -1;
     
    return dist[dst];


    }
};