class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int>prefix(n+1,0);
        prefix[0]=0;

        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];

        }
        deque<int>dq;
        for(int i=0;i<prefix.size();i++){
            while(!dq.empty() && prefix[i]- prefix[dq.front()]>=k){
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[dq.back()]>=prefix[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
       return ans==INT_MAX?-1:ans;
       
    }
};