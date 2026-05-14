class Solution {
public:
 bool bfs(int n, vector<vector<int>>& edges, int source, int target, int k,int threshold){
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
         vector<int> dist(n, INT_MAX);

        deque<int> dq;

        dist[source] = 0;
        dq.push_front(source);

        while(!dq.empty()) {

            int node = dq.front();
            dq.pop_front();

            for(auto &it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                
                int cost = (wt > threshold) ? 1 : 0;

                if(dist[node] + cost < dist[adjNode]) {

                    dist[adjNode] = dist[node] + cost;

                   
                    if(cost == 0)
                        dq.push_front(adjNode);
                    else
                        dq.push_back(adjNode);
                }
            }
        }

        return dist[target] <= k;

 }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
    

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