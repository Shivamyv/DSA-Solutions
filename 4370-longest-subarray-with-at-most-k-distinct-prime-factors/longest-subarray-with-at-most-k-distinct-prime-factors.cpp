class Solution {
public:
vector<int> factor(int n){
     vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
        ans.push_back(i);
      while(n%i==0){
        n/=i;
        }
        }
    }
     if(n>1) ans.push_back(n);
    return ans;
}
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
         int l=0,r=0;
        unordered_map<int,int>mpp;
        int maxlen=0;
       while(r<n){
        for(int p:factor(nums[r]))
        mpp[p]++;

        while(mpp.size()>k){
            for(int q:factor(nums[l])){
            mpp[q]--;

            if(mpp[q]==0) mpp.erase(q);
            }
            l++;
        }
     
        maxlen=max(maxlen,r-l+1);
      
      r++;

       }
       return maxlen;
        
    }
};