class Solution {
public:
 int f(int i,vector<int>& nums,vector<int>&dp){
    int n=nums.size();
     if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    
    int take=nums[i]+f(i+2,nums,dp);
    int nottake=f(i+1,nums,dp);
    

    return dp[i]=max(take,nottake);

 }
 int solve(vector<int>& nums){
     int n=nums.size();
        vector<int>dp(n,-1);
     return f(0,nums,dp);
 }
    int rob(vector<int>& nums) {
        int n=nums.size();
       if(n==1) return nums[0];
       vector<int>temp1,temp2;
       for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(nums[i]);
        }
         if(i!=n-1){
            temp2.push_back(nums[i]);
        }
       }
       return max(solve(temp1),solve(temp2));

        
    }
};