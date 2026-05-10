class Solution {
public:
  int f(int i,vector<int>& nums, int target,vector<int>&dp){
    int n=nums.size();
    if(i==n-1) return dp[i]=0;
    int ans=INT_MIN;
    if(dp[i]!=INT_MIN) return dp[i];
    for(int j=i+1;j<n;j++){
        if(abs(nums[i]-nums[j])<=target){
            int temp=1+f(j,nums,target,dp);
            ans=max(ans,temp);

        }
    }
    return dp[i]=ans;

  }

    int maximumJumps(vector<int>& nums, int target) {
       int n=nums.size();  
        vector<int>dp(n+1,INT_MIN);
        int result=f(0,nums,target,dp);
        return result<0?-1:result;

    }
};