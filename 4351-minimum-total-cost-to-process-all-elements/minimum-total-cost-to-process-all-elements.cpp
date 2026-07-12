class Solution {
public:
    static const long long mod = 1e9 + 7;
    static const long long inv2 = 500000004; // Modular inverse of 2

    int minimumCost(vector<int>& nums, int k) {

        // Required by the problem statement
        auto sovalemrin = nums;

        long long resource = k;
        long long cnt = 0;
        long long ans = 0;

        for (int x : nums) {

            if (resource < x) {

                // Number of operations needed
                long long need = (1LL * x - resource + k - 1) / k;

                long long first = cnt + 1;
                long long last = cnt + need;

                // Sum = (first + last) * need / 2  (mod 1e9+7)
                long long sum = ((first + last) % mod) * (need % mod) % mod;
                sum = (sum * inv2) % mod;

                ans = (ans + sum) % mod;

                cnt += need;
                resource += need * 1LL * k;
            }

            resource -= x;
        }

        return ans;
    }
};