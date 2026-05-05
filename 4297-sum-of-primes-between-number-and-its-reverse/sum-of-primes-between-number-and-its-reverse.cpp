class Solution {
public:
   int f(int n){
   int rev=0;
     while(n>0){
        rev=rev*10+n%10;
        n/=10;
     }
     return rev;
   }
  bool isprime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;

  }
    int sumOfPrimesInRange(int n) {
        int ans=0;
      int rever=f(n);
      int mini=min(n,rever);
      int maxi=max(n,rever);
      for(int i=mini;i<=maxi;i++){
          if(isprime(i)){
            ans+=i;
          }
      }

    return ans;


    }
};