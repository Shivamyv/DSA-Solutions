class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int r=0,l=0;
        int maxlen=0;
        while(r<n){
            mpp[nums[r]]++;
           while(mpp[nums[r]]>k){
             mpp[nums[l]]--;
            l++;
           }
           maxlen=max(maxlen,r-l+1);
           r++;

        }
       return maxlen;


    }
};