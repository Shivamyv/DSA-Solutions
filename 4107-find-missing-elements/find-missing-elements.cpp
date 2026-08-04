class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans;
       int minelement=*min_element(nums.begin(),nums.end());
       int maxelement=*max_element(nums.begin(),nums.end());
       unordered_set<int>st(nums.begin(),nums.end());
       for(int i=minelement;i<=maxelement;i++){
        if(st.find(i)==st.end()){
            ans.push_back(i);
        }
       }
       return ans;
       
    }
};