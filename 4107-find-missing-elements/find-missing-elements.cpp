class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans;
       int minelement=*min_element(nums.begin(),nums.end());
       int maxelement=*max_element(nums.begin(),nums.end());
       unordered_map<int,int>mpp;
       for(auto it:nums){
        mpp[it]++;
       } 
    
       for(int i=minelement;i<=maxelement;i++){
        if(mpp.find(i)==mpp.end()){
            ans.push_back(i);
        }
       }
       return ans;
       
    }
};