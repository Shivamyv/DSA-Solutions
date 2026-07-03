class Solution {
public:
int f(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
    int n=coins.size();
   if(amount==0) return 0;
   if(i==n) return 1e9;
   if(dp[i][amount]!=-1) return dp[i][amount];

    int take=1e9;
    if(i<n && amount >= coins[i]){
     take=1+f(i,coins,amount-coins[i],dp);
    }
     int nottake=f(i+1,coins,amount,dp);

     return dp[i][amount]= min(take,nottake);
    
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans= f(0,coins,amount,dp); 
        if(ans>=1e9) return -1;
        return ans;
    }
};