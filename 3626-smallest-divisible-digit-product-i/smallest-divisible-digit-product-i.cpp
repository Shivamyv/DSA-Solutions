class Solution {
public:
    int smallestNumber(int n, int t) {
      
       for(int i=n;i<=100;i++){
           int product=1;
           int cnt=i;
        while(cnt>0){
            int x=cnt%10;
            product*=x;
            
            cnt/=10;
        }
        if(product % t==0) {
            return i;
        }
       }
       return 0;
       
    }
};