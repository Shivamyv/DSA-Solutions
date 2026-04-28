class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Flatten
        for (auto &row : grid) {
            for (auto &num : row) {
                arr.push_back(num);
            }
        }
        
        // Check feasibility
        int base = arr[0];
        for (int num : arr) {
            if ((num - base) % x != 0) return -1;
        }
        
        // Sort
        sort(arr.begin(), arr.end());
        
        // Median
        int n = arr.size();
        int median = arr[n / 2];
        
        // Calculate operations
        int ans = 0;
        for (int num : arr) {
            ans += abs(num - median) / x;
        }
        
        return ans;
    }
};