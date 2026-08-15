class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
       int xort=0;
       bool flag=true;
       for(int x:nums){
         xort=xort^x;

       
       if(x!=0) flag=false;
       }
       if(flag){
       
        return 0;
       }
       return xort==0?n-1:n;
     


    }
};