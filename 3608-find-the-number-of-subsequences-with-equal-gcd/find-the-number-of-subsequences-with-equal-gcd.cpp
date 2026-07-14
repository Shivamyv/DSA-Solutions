class Solution {
public:
  const long long mod=1e9+7;
  int dp[201][201][201];
  int gcd(int a,int b){
     if(b==0)  return a;
    if(a==0) return b;
   return gcd(b,a%b);
      
  }
   
    int subsequencePairCount(vector<int>& nums) {
      int n=nums.size();
      int mx=*max_element(nums.begin(),nums.end());
      for(int first=0;first<201;first++){
        for(int second=0;second<201;second++){
            if(first==0 ||second==0){
                dp[n][first][second]=0;
            }
        else{
              dp[n][first][second]= (first==second);
       }
      }
      }
      for(int ind=n-1;ind>=0;ind--){
        for(int first=0;first<=mx;first++){
            for(int second=0;second<=mx;second++){
       int skip=dp[ind+1][first][second];
        int seq1=dp[ind+1][gcd(first,nums[ind])][second];
        int seq2=dp[ind+1][first][gcd(second,nums[ind])];
        long long ans=(1LL*skip+seq1+seq2) %mod;
          dp[ind][first][second]=ans;

            }
        }
      }

    return dp[0][0][0];

      

    }
};