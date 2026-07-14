class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n =prices.size();
  
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
          
        for(int buy=0;buy<=1;buy++){
            for(int cnt=0;cnt<=2;cnt++){
                dp[n][buy][cnt]=0;

            }
        }
        for(int ind=0;ind<=n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][2]=0;
            }
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt>=0;cnt--){
                    int profit=0;

          if(buy==0 ){
        profit= max(dp[ind+1][0][cnt],(-1)*prices[ind]+dp[ind+1][1][cnt]);
         }
         else{
        profit= max(dp[ind+1][1][cnt],prices[ind]+dp[ind+1][0][cnt+1]);
     }
      dp[ind][buy][cnt]=profit;   

                }
            }
        }

   return dp[0][0][0];

    }
};