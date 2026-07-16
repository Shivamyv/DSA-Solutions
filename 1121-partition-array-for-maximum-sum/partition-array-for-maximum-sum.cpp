class Solution {
public:
  int f(int ind,int k,vector<int>& arr,vector<int>&dp){
             int n=arr.size();
        int mx=INT_MIN;
        int sum=INT_MIN;
        if(dp[ind]!=-1) return dp[ind];
         if(ind==arr.size()) return 0;
        for(int i=ind;i<min(n,ind+k);i++){
             mx=max(mx,arr[i]);
            int ans=(i-ind+1)*mx+f(i+1,k,arr,dp);
            sum=max(sum,ans);
        }
        return dp[ind]= sum;   

  }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n=arr.size();
      vector<int>dp(n+1,-1);
    return f(0,k,arr,dp);  


    }
};