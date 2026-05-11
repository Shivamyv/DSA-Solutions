class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int>cnt;
      
      for(int i=0;i<n;i++){
      string ans=to_string(nums[i]);
       for(char ch:ans){
        cnt.push_back(ch-'0');
       }
     
      }
      
   return cnt;

    }
};