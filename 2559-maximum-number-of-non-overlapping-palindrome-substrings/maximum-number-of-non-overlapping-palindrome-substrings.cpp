class Solution {
public:
 vector<vector<bool>> check;
    void build(string &s) {
        int n = s.size();
        check.assign(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if (len == 1) {
                    check[l][r] = true;
                }
                else if (len == 2) {
                    check[l][r] = (s[l] == s[r]);
                }
                else {
                    check[l][r] =
                        (s[l] == s[r]) && check[l + 1][r - 1];
                }
            }
        }
    }


 int f(int i,string s, int k, vector<int>&dp){
     int n=s.size();
     if(i>=n) return 0;
     if(dp[i]!=-1) return dp[i];
     int ans=f(i+1,s,k,dp);
     
    for(int j=i+k-1;j<n;j++){
        if(check[i][j]){
       ans=max(ans,1+f(j+1,s,k,dp));

        }
    }
    return dp[i]=ans;
 }
    int maxPalindromes(string s, int k) {
       int  n=s.size();
       if(k==1) return n;
         build(s);
        vector<int>dp(n+1,-1);
      return f(0,s,k,dp);
       
    }
};