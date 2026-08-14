class Solution {
public:
  void f(int i,vector<int>& candidates, int target,vector<int>&temp,vector<vector<int>>&ans){
    int n=candidates.size();
    if(i==n || target < 0) return ;

    if(target==0){
        ans.push_back(temp);
        return;
    }
     temp.push_back(candidates[i]);
     f(i,candidates,target-candidates[i],temp,ans);
     temp.pop_back();
      f(i+1,candidates,target,temp,ans);

    
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,candidates,target,temp,ans);
        return ans;
        
    }
};