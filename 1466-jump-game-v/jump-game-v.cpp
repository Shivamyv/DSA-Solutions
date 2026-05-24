class Solution {
public:
  int f(int i,vector<int>& arr, int d, vector<int>&dp){
    if(dp[i]!=-1) return dp[i];
    int n =arr.size();
     int result=1;
    

    for(int j=i-1;j>=max(0,i-d);j--){
        if(arr[j]>=arr[i]) break;
        result=max(result,1+f(j,arr,d,dp));
    }
    for(int j=i+1;j<=min(n-1,i+d);j++){
        if(arr[j]>=arr[i]) break;
        result=max(result,1+f(j,arr,d,dp));
    }
   return dp[i]=result;
      

  }

    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        
        vector<int>dp(n,-1);
        int result=1;
         
         for(int i=0;i<n;i++){
           result=max(result,f(i,arr,d,dp));
         }
      return result;

    }
};

