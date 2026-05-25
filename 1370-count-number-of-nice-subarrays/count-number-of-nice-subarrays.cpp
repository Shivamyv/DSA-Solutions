class Solution {
public:
int f(vector<int>& nums, int k){
     int n=nums.size();
      int l=0,r=0;
      int cnt=0;
      int count=0;
      while(r<n){
         if(nums[r]%2==1) cnt++;

         while(cnt>k){
             if(nums[l]%2==1){
                cnt--;
             }
               l++;
            
         }

       count+=r-l+1;
         r++;


      }
      return count;
}



    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};