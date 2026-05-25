class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int n=nums.size();
        int ans=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y ) continue;
                int cost=0;
                for(int i=0;i<n;i++){
                    int rem=nums[i]%k;
                    if(i%2==0){
                    int diff = abs(rem - x);
                        cost+=min(diff,k-diff);
                    }
                    else{
                        int diff = abs(rem - y);
                        cost+=min(diff,k-diff);
                    }
                }
            
            ans=min(ans,cost);
        }
        }
        return ans;


    }
};