class Solution {
public:
    void f(int i, vector<int>& candidates, int target,
           vector<int>& temp, vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        int n = candidates.size();

        for(int j = i; j < n; j++) {

            // Skip duplicate choices at this level
            if(j > i && candidates[j] == candidates[j - 1])
                continue;

            // Since sorted, everything after this is also too large
            if(candidates[j] > target)
                break;

            temp.push_back(candidates[j]);

            // j+1 because each element can be used only once
            f(j + 1, candidates, target - candidates[j], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        f(0, candidates, target, temp, ans);

        return ans;
    }
};