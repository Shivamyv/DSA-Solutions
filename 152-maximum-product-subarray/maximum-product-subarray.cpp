class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        if(n==1) return nums[0];
          
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=i;j<n;j++){
            product*=nums[j];
                ans=max(ans,product);
            }
        }
        return ans;
    }
};