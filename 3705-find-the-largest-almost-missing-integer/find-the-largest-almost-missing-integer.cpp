class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
      int n=nums.size();
      unordered_map<int,int>mpp;
      for(int i=0;i<=n-k;i++){
        unordered_set<int>st;
        for(int j=i;j<i+k;j++){
           st.insert(nums[j]);
        }
        for(int x:st){
            mpp[x]++;
        }

      }
      int ans=-1;
      for(auto it:mpp){
        int no=it.first;
        int count=it.second;
        if(count==1){
            ans=max(ans,no);
        }
      }
     return ans;

    }
};