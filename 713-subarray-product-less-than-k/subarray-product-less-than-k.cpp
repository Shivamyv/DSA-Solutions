class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int product=1;
        int cnt=0;
        if(k<=1) return 0;
        while(r<n){
            product*=nums[r];
            while(product>=k){
                product/=nums[l];
                l++;

            }
            cnt+=(r-l+1);
            r++;
            
        }
        return cnt;
    }
};