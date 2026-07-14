class Solution {
public:
int dp[10001][2][101];
int f(int ind,int buy,int k,vector<int>&prices,int cnt){
    int n=prices.size();
       
       int profit=0;
       if(ind ==n || cnt==k) return 0;
       if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
      if(buy==0){
         profit=max(0+f(ind+1,0,k,prices,cnt),
         (-1)*prices[ind]+f(ind+1,1,k,prices,cnt));
    }
    else {
      profit=max(0+f(ind+1,1,k,prices,cnt),
      prices[ind]+f(ind+1,0,k,prices,cnt+1));
    }
    return  dp[ind][buy][cnt]=profit;

}
    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
      int cnt=0;
      memset(dp,-1,sizeof(dp));
      return f(0,0,k,prices,cnt);  


    }
};