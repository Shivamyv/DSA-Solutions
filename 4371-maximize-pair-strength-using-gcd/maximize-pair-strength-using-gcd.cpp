class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
       int n=nums.size();
       long long ans=0;
       long long cnt=0;
       for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long gcdfind=__gcd(nums[i],nums[j]);
            ans=(1LL*nums[i]*nums[j])/(1LL*gcdfind*gcdfind);
          cnt=max(cnt,ans);
        }
       }   
       return cnt;     


    }
};