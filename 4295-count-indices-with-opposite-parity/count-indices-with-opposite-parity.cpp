class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
       vector<int>ans;
       int n=nums.size(); 
     
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                int cnt=0;
                for(int j=i+1;j<n;j++){
                    if(nums[j]%2!=0){
                        cnt++;
                        
                    }
                }
                ans.push_back(cnt);
            }
             int cnteven=0;
             if(nums[i]%2!=0){
                for(int j=i+1;j<n;j++){
                    
                    if(nums[j]%2==0){
                         cnteven++;
                        
                    }
                }
                  ans.push_back(cnteven);
                  
            }
        }
        return ans;

    }
};