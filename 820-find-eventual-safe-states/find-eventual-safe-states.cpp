class Solution {
public:
vector<int>topo(int V,vector<int>adj[]){
    
    vector<int>outdegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            outdegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(outdegree[i]==0) q.push(i);
        
    }
    vector<int>safenode;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it:adj[node]){
            outdegree[it]--;
            if(outdegree[it]==0) q.push(it);
        }


    }
    
    sort(safenode.begin(),safenode.end());
    return safenode;

}



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
       vector<int>adj[V];
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }
      return topo(V,adj);



    }
};