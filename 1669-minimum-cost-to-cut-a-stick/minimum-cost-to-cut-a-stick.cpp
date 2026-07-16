class Solution {
public:
   int f(int i, int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j) return 0;
    int mini=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    
    for(int ind=i;ind<=j;ind++){
    int ans=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
    mini=min(mini,ans);


    }

   return dp[i][j]=mini;



   }
   
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();

        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return f(1,c-2,cuts,dp);

    }
};