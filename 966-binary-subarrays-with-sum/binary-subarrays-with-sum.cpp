class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return atMost(nums, goal) - atMost(nums, goal - 1);
    }

      int atMost(vector<int>& nums, int goal){
       int n=nums.size();
       int sum=0;
       int maxlen=0;
       int l=0,r=0;
       while(r<n){
        if(goal <0) return 0;
          sum+=nums[r];
          while(sum>goal){
             sum-=nums[l];
             l++;
          }
          maxlen+=r-l+1;
          r++;
       }

     
     
        return maxlen;
     
      }


};