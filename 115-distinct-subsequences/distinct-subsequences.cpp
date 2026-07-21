class Solution {
public:
const long long mod=1e9+7;
   int f(int i,int j,string &s,string &t, vector<vector<int>>&dp){
        int n=s.size();
        int m=t.size();
       if(j<0) return 1;
       if(i<0) return 0; 
      if(dp[i][j]!=-1) return dp[i][j];

        int result=0;
        if(s[i]==t[j]){
            int move=f(i-1,j-1,s,t,dp);
            int notmove=f(i-1,j,s,t,dp);
            result=(move+notmove)%mod;
            
        }
        else{
            result=f(i-1,j,s,t,dp);
        }
       return dp[i][j]= result;

   }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s,t,dp);



    }
};