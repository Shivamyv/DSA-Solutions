class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
      int n=nums.size();
      long long ans=0;
      long long currentsum=0;
      long long validleftpoints=0;
      unordered_map<int,int>mpp;
      mpp[0]=1;
      for(int i=0;i<n;i++){
          if(nums[i]==target){
           validleftpoints+=mpp[currentsum];
           currentsum++;
          }
          else{
            currentsum--;
            validleftpoints-=mpp[currentsum];
          }
          mpp[currentsum]++;
          ans+=validleftpoints;
    
      }
      return ans;


    }
};