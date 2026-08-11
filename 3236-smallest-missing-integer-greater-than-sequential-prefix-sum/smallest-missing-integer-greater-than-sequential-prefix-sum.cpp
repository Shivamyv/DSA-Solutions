class Solution {
public:
    int missingInteger(vector<int>& nums) {
    
        int n=nums.size();
         vector<int>prefix(n);
         prefix[0]=nums[0];
         for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
         }
         unordered_set<int>st(nums.begin(),nums.end());
         int curindex=0;
         int sum=nums[0];
         for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
               sum+=nums[i];

            }
            else{
               
                break;
            }
         }
        

          for(int k=sum;k<=1e9;k++){
            if(st.find(k)==st.end())
            return k;
          }
        
    return 0;

    }
};