class Solution {
public:
int f(int ind,int buy,vector<int>&prices,int cnt, vector<vector<vector<int>>> &dp){
    int n=prices.size();
    if(ind==n || cnt==2) return 0;
    if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];


    int profit=0;
    
    if(buy==0 ){
        profit= max(0+f(ind+1,0,prices,cnt,dp),(-1)*prices[ind]+f(ind+1,1,prices,cnt,dp));
    }
     if(buy==1 && cnt<=2){
        profit= max (0+f(ind+1,1,prices,cnt,dp),prices[ind]+f(ind+1,0,prices,cnt+1,dp));
     }
     return dp[ind][buy][cnt]=profit;

}
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int cnt=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return f(0,0,prices,cnt,dp);   


    }
};