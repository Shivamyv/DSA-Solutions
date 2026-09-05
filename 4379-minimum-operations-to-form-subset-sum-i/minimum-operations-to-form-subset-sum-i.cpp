class Solution {
public:
int f(int i,vector<int>&nums,int sum, vector<vector<int>>&dp){
    int n=nums.size();
    if(sum==0) return 0;
    if(i==n) return 1e9;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int ans=f(i+1,nums,sum,dp);
    int val=nums[i];
    int cost=0;

    while(val<=sum){
        ans=min(ans,cost+f(i+1,nums,sum-val,dp));
        val*=2;
        cost++;
    }

   val=nums[i];
   cost=0;
   while(val>0){
    if(val<=sum){
    ans=min(ans,cost+f(i+1,nums,sum-val,dp));
    }
    val/=2;
    cost++;
   }
   return dp[i][sum]=ans;

}
    int minOperations(vector<int>& nums, int sum) {
     int n=nums.size();
      vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    int ans= f(0,nums,sum,dp);
    return ans==1e9?-1:ans;


    }
};