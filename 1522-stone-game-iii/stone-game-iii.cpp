class Solution {
public:
int f(int i,vector<int>& stoneValue,vector<int>&dp){
    int n=stoneValue.size();
       if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

     int sum=0;
     int ans=INT_MIN;
     for(int k=i;k<min(i+3,n);k++){
        sum+=stoneValue[k];
        ans=max(ans,sum-f(k+1,stoneValue,dp));
     }

   return dp[i]=ans;

      

}
    string stoneGameIII(vector<int>& stoneValue) {
       int n=stoneValue.size();
       vector<int>dp(n,-1);
       
     int ans =f(0,stoneValue,dp);
     if(ans>0) return "Alice";
     else if(ans<0) return "Bob";
    else return "Tie";

    }
};