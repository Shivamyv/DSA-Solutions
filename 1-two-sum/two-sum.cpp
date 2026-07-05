class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int>ans;
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        int find=target-nums[i];
        if(mpp.count(find)) {
           ans.push_back(mpp[find]);
            ans.push_back(i);
            
        }
        mpp[nums[i]]=i;
    }

      return ans; 
    }
};