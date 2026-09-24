class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            while(nums[i]>0){
                int cnt=nums[i]%10;
                sum+=cnt;
                nums[i]/=10;
            }
            if(i==sum) return i;
        }
        return -1;
    }
};