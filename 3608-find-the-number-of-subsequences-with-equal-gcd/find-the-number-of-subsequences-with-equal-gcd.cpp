class Solution {
public:
  const long long mod=1e9+7;
  int dp[201][201][201];
  
  int gcd(int a,int b){
     if(b==0)  return a;
    if(a==0) return b;
   return gcd(b,a%b);
      
  }
   int f(int ind,int first,int second,vector<int>&nums){
    int n=nums.size();
    if(ind==n){
        if(first==0 ||second==0) return 0;
        else
       return (first==second);
    }
    if(dp[ind][first][second]!=-1) return dp[ind][first][second];

      int skip=f(ind+1,first,second,nums);
      int seq1=f(ind+1,gcd(first,nums[ind]),second,nums);
      int seq2=f(ind+1,first,gcd(second,nums[ind]),nums);
      long long ans=(1LL*skip+seq1+seq2) %mod;
      
      return dp[ind][first][second]=ans;


   }
    int subsequencePairCount(vector<int>& nums) {
      int n=nums.size();
      memset(dp,-1,sizeof(dp));
      return f(0,0,0,nums);  

    }
};