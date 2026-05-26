class Solution {
public:
    int topo(int n,vector<int>adj[]) {
        
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);

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
        return toposort.size()==n;
    }
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n=prerequisites.size();
        vector<int>adj[numCourses];
       for(auto it:prerequisites){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
       }
   return topo(numCourses,adj);


    }
};