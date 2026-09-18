class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
       for(int r:nums){
            sum+=r;
            if(mpp.find(sum-k)!=mpp.end()){
               cnt+= mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;

    }
};