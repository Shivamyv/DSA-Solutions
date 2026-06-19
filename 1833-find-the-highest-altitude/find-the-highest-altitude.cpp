class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>ans(n+1);
        ans[0]=0;
        ans[1]=gain[0];
        for(int i=1;i<n;i++){
            ans[i+1]=gain[i]+ans[i];
        }
        return *max_element(ans.begin(),ans.end());
       
    }
};