class Solution {
public:
bool check(string s){
     if (s[0] == '0') return false;

    long long num = 0;

    for (char c : s) {
        num = num * 2 + (c - '0');

        if (num > 1000000) return false;
    }

    while (num % 5 == 0)
        num /= 5;

    return num == 1;

}
  
  int f(int i,string &s,vector<int>&dp){
    int n=s.size();
     if(i>=n) return 0;
     if(dp[i]!=-1) return dp[i];
     int ans=INT_MAX;
     for(int k=i;k<n;k++){
       string part=s.substr(i,k-i+1);
       if(check(part)){
        int next=f(k+1,s,dp);
        if(next!=-1){
            ans=min(ans,1+next);
        }
       }
      
     }

     if(ans==INT_MAX) return dp[i] =-1;
     return dp[i]=ans;   

  }



    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,dp);

    }
};