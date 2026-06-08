class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>less;
        vector<int>greater;
        vector<int>equal;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                greater.push_back(nums[i]);
            }
            else{
                equal.push_back(nums[i]);
            }
        }
        vector<int>ans;
       for(int x:less){
        ans.push_back(x);

       }
       for(int y:equal) ans.push_back(y);
       for(int z:greater) ans.push_back(z); 





     return ans;

    }
};