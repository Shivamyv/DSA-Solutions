class Solution {
public:
    using ll = long long;

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

        vector<vector<pair<ll,ll>>> graph1(n), graph2(n);

        // build graphs
        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int c = it[2];
            int t = it[3];

            graph1[u].push_back({v, c});
            graph1[v].push_back({u, c});

            graph2[u].push_back({v, 1LL * c * t});
            graph2[v].push_back({u, 1LL * c * t});
        }

        vector<int> ans;
        ll INF = 1e18;

        for(int s = 0; s < n; s++) {

            // first dijkstra
            vector<ll> dist1(n, INF);

            priority_queue<
                pair<ll,ll>,
                vector<pair<ll,ll>>,
                greater<pair<ll,ll>>
            > pq;

            dist1[s] = 0;
            pq.push({0, s});

            while(!pq.empty()) {

                auto [wt, node] = pq.top();
                pq.pop();

                for(auto &it : graph1[node]) {

                    ll adjNode = it.first;
                    ll edgeWt  = it.second;

                    if(dist1[adjNode] > wt + edgeWt) {

                        dist1[adjNode] = wt + edgeWt;

                        pq.push({dist1[adjNode], adjNode});
                    }
                }
            }

            // second dijkstra
            vector<ll> dist2(n, INF);

            priority_queue<
                pair<ll,ll>,
                vector<pair<ll,ll>>,
                greater<pair<ll,ll>>
            > pq2;

            dist2[s] = 0;
            pq2.push({0, s});

            while(!pq2.empty()) {

                auto [wt, node] = pq2.top();
                pq2.pop();

                for(auto &it : graph2[node]) {

                    ll adjNode = it.first;
                    ll edgeWt  = it.second;

                    if(dist2[adjNode] > wt + edgeWt) {

                        dist2[adjNode] = wt + edgeWt;

                        pq2.push({dist2[adjNode], adjNode});
                    }
                }
            }

            // find minimum answer
            ll best = INF;

            for(int i = 0; i < n; i++) {

                best = min(best,
                           1LL * prices[i] + dist1[i] + dist2[i]);
            }

            ans.push_back(best);
        }

        return ans;
    }
};