class Solution {
public:
int dp[5001][2];
    int f(int ind,int buy,vector<int>&prices){
        int n=prices.size();
        if(ind>=n) return 0;
        int profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==0){
            profit=max(0+f(ind+1,0,prices),(-1)*prices[ind]+f(ind+1,1,prices));
        }
        else{
           profit=max(0+f(ind+1,1,prices),prices[ind]+f(ind+2,0,prices)); 
        }
        return dp[ind][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
       return f(0,0,prices);

    }
};