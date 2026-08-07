class Solution {
public:
bool f(int i,vector<int>& nums,vector<int>&dp){
    int n=nums.size();
    if(i>=n-1) return true;
    if(dp[i]!=-1) return dp[i];

    for(int k=1;k<=nums[i];k++){
        if(f(i+k,nums,dp)) return dp[i]=true;
    }
     return dp[i]=false;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
       return f(0,nums,dp);
       
    }
};