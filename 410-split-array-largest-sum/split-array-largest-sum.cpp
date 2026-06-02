class Solution {
public:
  bool possible(vector<int>& nums, int k,int mid){
      int n=nums.size();
      int sum=0;
      int cnt=1;
      for(int i=0;i<n;i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }
        else{
            sum=nums[i];
            cnt++;

        }

      }
      return cnt<=k;
  }


    int splitArray(vector<int>& nums, int k) {
      int n=nums.size();
      int low=*max_element(nums.begin(),nums.end());
      int high=accumulate(nums.begin(),nums.end(),0);
     int ans=0;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(nums,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
     return ans;

    }
};