class Solution {
public:
int f(int i,vector<int>&nums,vector<int>&dp){
    int n=nums.size();
    if(i>=n) return 0; 
    int take=0,nottake=0;
    if(dp[i]!=-1) return dp[i];
    if(i<n)
     take=nums[i]+f(i+2,nums,dp);
    if(i<n)
     nottake=0+f(i+1,nums,dp);

    return dp[i]=max(take,nottake);
    
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
      return f(0,nums,dp);
    }
};