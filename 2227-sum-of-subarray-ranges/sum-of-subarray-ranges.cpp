class Solution {
public:
  vector<int> nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int currelement=arr[i];
            while(!st.empty() && arr[st.top()]>=currelement){
                st.pop();
            }

            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;

    }


     vector<int> pse(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int currelement=arr[i];
            while(!st.empty() && arr[st.top()]>currelement){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
  
  vector<int> pge(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int currelement=arr[i];
            while(!st.empty() && arr[st.top()]<currelement){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nge(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int currelement=arr[i];
            while(!st.empty() && arr[st.top()]<=currelement){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }









    long long subArrayRanges(vector<int>& nums) {
       int n=nums.size();
    vector<int> psee = pse(nums);
vector<int> nsee = nse(nums);
vector<int> pgee = pge(nums);
vector<int> ngee = nge(nums);

long long ans = 0;

for(int i=0;i<n;i++){

    long long maxCnt =
        1LL * (i - pgee[i]) * (ngee[i] - i);

    long long minCnt =
        1LL * (i - psee[i]) * (nsee[i] - i);

    ans += 1LL * nums[i] * (maxCnt - minCnt);
}

return ans;




    }
};