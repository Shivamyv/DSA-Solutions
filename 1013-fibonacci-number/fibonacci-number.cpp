class Solution {
public:
    int fib(int n) {
      int ans=0;
      if(n<=1) return n;
      ans+=fib(n-1)+fib(n-2);
      
      return ans;

    }
};