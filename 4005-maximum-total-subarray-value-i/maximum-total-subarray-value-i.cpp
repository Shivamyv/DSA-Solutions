class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long z=0;
        long long x=*max_element(nums.begin(),nums.end());
       long long y=*min_element(nums.begin(),nums.end());
        z=x-y;
        z*=k;
        return z;


    }
};