class Solution {
public:
   int mod=1e9+7;

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



    int sumSubarrayMins(vector<int>& arr) {
         int n=arr.size();
         int sum=0;
         vector<int>nsee=nse(arr);
         vector<int>psee=pse(arr);
         for(int i=0;i<n;i++){
            int right=nsee[i]-i;
            int left=i-psee[i];
            long long freq=right*left*1LL;
            int val=(freq*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;
         }
   
     return sum;


    }
};