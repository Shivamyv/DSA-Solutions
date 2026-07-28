class Solution {
public:
int f(vector<int>& nums, int L, int M){
    int n=nums.size();
    int lsum=0;
    int msum=0;
    for(int i=0;i<=L+M-1;i++){
        if(i<L){
            lsum+=nums[i];
        }
        else{
            msum+=nums[i];
        }
    }
    int maxlsum=lsum;
    int result=maxlsum+msum;
    for(int j=L+M;j<n;j++){
        lsum+=nums[j-M]-nums[j-M-L];
        msum+=nums[j]-nums[j-M];
        maxlsum=max(maxlsum,lsum);
        result=max(result,maxlsum+msum);
    }
   return result;



}
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n=nums.size();
        return max(f(nums,L,M),f(nums,M,L));
       
    }
};