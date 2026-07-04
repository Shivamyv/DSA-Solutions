class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>>adj[n+1];
    for(auto it:roads){
        int a=it[0];
        int b=it[1];
        int distance=it[2];
        adj[a].push_back({b,distance});
        adj[b].push_back({a,distance});

    }        
    int mini=INT_MAX;
   queue<int>q;
  vector<int>vis(n+1,false);
   q.push(1);
  vis[1]=true;
   while(!q.empty()){
    int node=q.front();
    q.pop();
   
  
   for(auto it:adj[node]){
    int v=it.first;
    int edgewt=it.second;
   mini=min(mini,edgewt);

    if(!vis[v]) {
        vis[v]=true;
        q.push(v);
    }
   }
   }

  

   return mini;


    }
};