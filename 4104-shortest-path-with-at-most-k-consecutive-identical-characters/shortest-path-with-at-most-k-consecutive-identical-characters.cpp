class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
      vector<pair<int,int>>adj[n];
      vector<vector<int>>dist(n,vector<int>(k+1,1e9));
      for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
      }
      priority_queue<pair<int,pair<int,int>>,
      vector<pair<int,pair<int,int>>>,
      greater<pair<int,pair<int,int>>>>pq;
      pq.push({0,{0,1}});
      dist[0][1]=1;
     
      while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           int d=it.first;
           int u=it.second.first;
           int count=it.second.second;
           if(d>dist[u][count]) continue;

           if(u==n-1) return d;

           for(auto & edge:adj[u]){
           int v=edge.first;
           int wt=edge.second;
           int next=1;
           if(labels[u]==labels[v]) 
           next=count+1;

           if(next>k) continue;
           if(d+wt<dist[v][next]){
            dist[v][next]=d+wt;
            pq.push({dist[v][next],{v,next}});
           }

      }
      }

    return -1;

        
    }
};