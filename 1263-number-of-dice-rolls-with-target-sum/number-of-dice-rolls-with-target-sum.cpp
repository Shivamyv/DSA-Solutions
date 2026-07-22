class Solution {
public:
const long long mod=1e9+7;
   int f(int ind,int target,int n,int k,vector<vector<int>>&dp){
    if(ind==n) return target==0;
    if(target<0) return 0;

    if(dp[ind][target]!=-1) return dp[ind][target];

    long long ans=0;
    for(int face=1;face<=k;face++){
        ans=(ans+f(ind+1,target-face,n,k,dp))%mod;
    }
    return dp[ind][target]=ans;

   }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(0,target,n,k,dp);
    }
};