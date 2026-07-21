class Solution {
public:
const long long mod=1e9+7;
   
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=0;i<=n;i++){
        dp[i][0]=1;
       }
       for(int j=1;j<=m;j++){
        dp[0][j]=0;
       }
         
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           
        if(s[i-1]==t[j-1]){
            int move=dp[i-1][j-1];
            int notmove=dp[i-1][j];
            dp[i][j]=(move+notmove)%mod;
            
        }
        else{
           dp[i][j] = dp[i-1][j] ;
        }
         
        }
       } 

     return dp[n][m];

    }
};