class Solution {
public:
vector<int>prefix;
  int prefixsum(int i,int j){
   
     if(i>j) return 0;

     if(i==0) return prefix[j];
     return prefix[j]-prefix[i-1];
  }
int f(int i,int j,vector<int>&stones,vector<vector<int>>&dp){
   
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=prefixsum(i+1,j)-f(i+1,j,stones,dp);
    int right= prefixsum(i,j-1) -f(i,j-1,stones,dp);
    
    return  dp[i][j]=max(left,right);

}
    int stoneGameVII(vector<int>& stones) {
      int n=stones.size();
     prefix.resize(n);
    prefix[0]=stones[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+stones[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     return f(0,n-1,stones,dp);

    }
};