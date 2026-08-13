class Solution {
public:
int f(int i,string &s,vector<int>&dp){
    int n=s.size();
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

      int ans=n-i;
      vector<int>freq(26,0);
      
      for(int k=i;k<n;k++){
        freq[s[k]-'a']++;

         int frequency=0;
        bool valid=true;

        for(int x=0;x<26;x++){
            if(freq[x]>0){
                if(frequency==0){
                    frequency=freq[x];

                }
                else if(freq[x]!=frequency){
                    valid=false;
                    break;

                }
            }
        }

     if(valid){
        ans=min(ans,1+f(k+1,s,dp));

     }

     }
    return  dp[i]=ans;



}
    int minimumSubstringsInPartition(string s) {
       int n=s.size();
       vector<int>dp(n+1,-1);
        return f(0,s,dp);

    }
};