class Solution {
public:
   vector<int> topo(int V,vector<int>adj[]){
      vector<int>indegree(V,0);
      for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
      }
      queue<int>q;
      for(int i=0;i<V;i++){
        if(indegree[i]==0)q.push(i);
      }
      vector<int>toposort;
      while(!q.empty()){
        int node=q.front();
          q.pop();
          toposort.push_back(node);
          for(auto it:adj[node]){
             indegree[it]--;
             if(indegree[it]==0) q.push(it);
          }
      }
    
    if(toposort.size()==V) return toposort;

     return {};
  

   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<int>adj[numCourses];
      for(auto it:prerequisites){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);

      }
       return topo(numCourses,adj); 
    }
};