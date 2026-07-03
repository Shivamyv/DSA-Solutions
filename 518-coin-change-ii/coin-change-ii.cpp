class Solution {
public:
int f(int i,int amount, vector<int>& coins, vector<vector<int>>&dp){
   int n=coins.size();
     
     if(amount==0) return 1;
    if(i==n) return 0;

    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=0;
    if(coins[i]<=amount && i<n){
        take=f(i,amount-coins[i],coins,dp);
        

    }
    int nottake=f(i+1,amount,coins,dp);
    return dp[i][amount]=take+nottake;


}
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);


    }
};