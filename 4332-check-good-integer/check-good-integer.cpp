class Solution {
public:
    bool checkGoodInteger(int n) {
        int normalsum=0;
        int squaresum=0;
        int nums=0;
        while(n>0){
         nums=n%10;
         normalsum+=nums;
         squaresum+=nums*nums;
         n/=10;
        }
       return squaresum-normalsum>=50 ;

         
    }
};