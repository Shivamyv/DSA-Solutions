class Solution {
public:
typedef long long ll;
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            ll currsum=0;
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                currsum+=nums[j];
                ll remove= (((ll)2*nums[j])%k+k)%k;
                st.insert(remove);
                ll sum=((currsum%k)+k)%k;
                if(sum==0 || st.find(sum)!=st.end()){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
      
     return maxlen;
       


    }
};