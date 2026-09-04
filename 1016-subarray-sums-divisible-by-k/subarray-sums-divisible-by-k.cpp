class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
       int prefixsum=0;
       unordered_map<int,int>mpp;
          mpp[0]=1;
       for(int i=0;i<n;i++){
        prefixsum+=nums[i];
        int rem= prefixsum%k;
         if(rem<0) rem+=k;
       
       if(mpp.find(rem)!=mpp.end()){
        ans+=mpp[rem];
       }
        mpp[rem]++;
       
       }
       

     return ans;
        
    }
};