class Solution {
public:
int kadanemax(vector<int>& nums){
    int n=nums.size();

     int sum=nums[0];
     int maxsum=nums[0];
     
     for(int i=1;i<n;i++){
        sum=max(sum+nums[i],nums[i]);
        maxsum=max(maxsum,sum);
     }
     return maxsum;
}
int kadanemin(vector<int>& nums){
    int n=nums.size();

     int sum=nums[0];
     int minsum=nums[0];
     
     for(int i=1;i<n;i++){
        sum=min(sum+nums[i],nums[i]);
        minsum=min(minsum,sum);
     }
     return minsum;
}


    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int minsum=kadanemin(nums);
        int maxsum=kadanemax(nums);
        int circularsum=sum-minsum;
        if(maxsum>0)
        return max(maxsum,circularsum);
         return maxsum;
        
    }
};