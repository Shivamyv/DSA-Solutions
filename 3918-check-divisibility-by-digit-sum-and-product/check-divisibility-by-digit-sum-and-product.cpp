class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int s=n;
       while(s>0){
        int last=s%10;
        sum+=last;
        product*=last;
        s/=10;
       } 
       if( n% (sum+product) ==0) return true;
       return false;
      

    }
};