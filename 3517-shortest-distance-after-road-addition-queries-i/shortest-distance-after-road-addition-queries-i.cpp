class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
     vector<vector<int>>adj(n);
     for(int i=0;i<n-1;i++){
        adj[i].push_back(i+1);
     }

 vector<int>ans;
     for(auto& it:queries){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
       
     
     vector<int>dist(n+1,1e9);
     queue<int>q;
     q.push(0);
     dist[0]=0;

    
     while(!q.empty()){
       int node=q.front();
        q.pop();
       
        for(auto& it:adj[node]){
            if(dist[node]+1 < dist[it]){
            dist[it]=dist[node]+1;
              q.push(it);

            }
        }
     }
     ans.push_back(dist[n-1]);
    }
    return ans;


    }
};