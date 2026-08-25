class Solution {
public:
bool f(int i,int target,vector<int>&nums, vector<vector<int>>&dp){
    int n=nums.size();
    if(i==n) return target==0;

    if(dp[i][target]!=-1) return dp[i][target];

     int nottake=f(i+1,target,nums,dp);
     int take=0;
     if(nums[i]<=target){
        take=f(i+1,target-nums[i],nums,dp);

     }
     return dp[i][target]=take||nottake;

}

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
         int sum=0;
         for(int i=0;i<n;i++){
            sum+=nums[i];
         }
         if(sum%2==1) return false;
         int diff=sum/2;
         vector<vector<int>>dp(n+1,vector<int>(diff+1,-1));
         return f(0,diff,nums,dp);



    }
};