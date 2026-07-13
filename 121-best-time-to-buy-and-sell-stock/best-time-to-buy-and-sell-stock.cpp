class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxprofit=0;
        for(int i=1;i<n;i++){
            int curprofit=prices[i]-mini;
            maxprofit=max(maxprofit,curprofit);
            mini=min(mini,prices[i]);


        }

     return maxprofit;

    }
};