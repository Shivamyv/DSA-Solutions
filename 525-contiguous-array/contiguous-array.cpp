class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     int n=nums.size();
     unordered_map<int,int>mpp;
     int sum=0;
     int length=0;
     mpp[0]=-1;
     for(int i=0;i<n;i++){
        if(nums[i]==0) sum+=-1;
        else{
            sum+=nums[i];
        }
      if(mpp.find(sum)!=mpp.end()){
      length=max(length,i-mpp[sum]);
     }
     else{
     mpp[sum]=i;
     }

     }
     return length;


    }
};