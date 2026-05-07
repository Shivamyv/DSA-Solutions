class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
       int n=nums.size();
       vector<int>prefixmax(n),suffixmin(n);
       prefixmax[0]=nums[0];
       suffixmin[n-1]=nums[n-1];
       for(int i=1;i<n;i++){
        int x=nums[i],y=nums[n-1-i];
        prefixmax[i]=max(prefixmax[i-1],x);
        suffixmin[n-1-i]=min(suffixmin[n-i],y);

       }     
       vector<int>ans(n);
       ans[n-1]=prefixmax[n-1];
       for(int i=n-2;i>=0;i--){
        if(prefixmax[i]>suffixmin[i+1]){
            ans[i]=ans[i+1];

        }
        else{
            ans[i]=prefixmax[i]; 
        }
       }  
     return ans;

    }
};