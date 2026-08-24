class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
     vector<vector<int>>ans;
      unordered_set<int>st(nums.begin(),nums.end());
       int start=-1;
     for(int i=lower;i<=upper;i++){
     if(st.find(i)==st.end()){
        if(start==-1){
            start=i;
        }
    
     }
     else{
      if(start!=-1){
      ans.push_back({start,i-1});
      start=-1;
      }
     }

     }
     if(start!=-1){
        ans.push_back({start,upper});
     }
     return ans;



    }
};