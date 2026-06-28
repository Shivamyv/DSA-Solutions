class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
       vector<pair<int,int>>adj[n];
       for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
       }

       priority_queue<pair<long long,pair<int,int>>,
       vector<pair<long long,pair<int,int>>>,
       greater<pair<long long,pair<int,int>>>>pq;
       const long long INF=1e18;

     vector<vector<long long>>dist(n,vector<long long>(power+1,INF));
       pq.push({0,{source,power}});
      dist[source][power]=0;

      
          while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long t = it.first;
            int u = it.second.first;
            int remPower = it.second.second;

            if (t != dist[u][remPower])
                continue;

            if (u == target)
                continue;

            if (remPower < cost[u])
                continue;

            for (auto edge : adj[u]) {

                int v = edge.first;
                int wt = edge.second;

                int newPower = remPower - cost[u];
                long long newTime = t + wt;

                if (newTime < dist[v][newPower]) {
                    dist[v][newPower] = newTime;
                    pq.push({newTime, {v, newPower}});
                }
            }
        }

        long long bestTime = INF;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {

            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            }
            else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, p);
            }
        }

        if (bestTime == INF)
            return {-1, -1};

        return {bestTime, bestPower};


    }
};