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
       
       return n% (sum+product) ==0;
      

    }
};