class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
           int u=it[0];
           int v=it[1];
           int wt=it[2];
           adj[u].push_back({v,wt});
           adj[v].push_back({u,wt});
        }  
        priority_queue<pair<long long,int>,vector<pair<long long, int>>,
                       greater<pair<long long,int>>> pq;
        vector<long long> mindist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        mindist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            long long dist = p.first;
            int node = p.second;
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int traveltime = it.second;
                if (mindist[adjnode] > dist + traveltime) {
                    mindist[adjnode] = dist + traveltime;
                    ways[adjnode] = ways[node];
                    pq.push({mindist[adjnode], adjnode});
                } else if (mindist[adjnode] == dist + traveltime) {
                    ways[adjnode]+=ways[node] % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};