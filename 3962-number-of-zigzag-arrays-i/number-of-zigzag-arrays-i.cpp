class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // DP states for length 2
        vector<long long> up(m, 0);
        vector<long long> down(m, 0);

        // Build length 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        // Allocate auxiliary vectors ONCE outside the loop to prevent MLE/churn
        vector<long long> prefUp(m + 1, 0);
        vector<long long> prefDown(m + 1, 0);
        vector<long long> newUp(m, 0);
        vector<long long> newDown(m, 0);

        // Build length 3 to n
        for (int len = 3; len <= n; len++) {
            // Compute prefix sums
            prefUp[0] = 0;
            prefDown[0] = 0;
            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            // Calculate new transitions
            for (int v = 0; v < m; v++) {
                // To end at v with an UP step, the previous step must have been a DOWN step ending at < v
                newUp[v] = prefDown[v];

                // To end at v with a DOWN step, the previous step must have been an UP step ending at > v
                newDown[v] = (prefUp[m] - prefUp[v + 1] + MOD) % MOD;
            }

            // Reuse vectors instead of reallocating memory
            up = newUp;
            down = newDown;
        }

        long long ans = 0;
        // Sum all valid configurations of length n
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};