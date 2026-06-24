class Solution {
public:
long long  f(vector<vector<int>>& obstacleGrid, vector<vector<long long>>&dp){
      int n= obstacleGrid.size();
       int m=obstacleGrid[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==n-1 && j==m-1){

                 dp[i][j]=1;
                continue;
                }
                long long right=0;
                long long bottom=0;
                if(i+1<n){
                    right=dp[i+1][j];
                }
                if(j+1<m) {
                bottom=dp[i][j+1];
                }

                dp[i][j]=right+bottom;
            }
        }
    
     return dp[0][0];
  


}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n= obstacleGrid.size();
       int m=obstacleGrid[0].size();
       vector<vector<long long>>dp(n,vector<long long>(m,0));
       return f( obstacleGrid,dp);
    }
};