class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
     int n=arr.size();
      int l=0,r=0;
      int currsum=0;
      int minlen=INT_MAX;
      int result=INT_MAX;
      vector<int>bestarr(n,INT_MAX);
      while(r<n){
        currsum+=arr[r];
       while(currsum > target){
           currsum-=arr[l];
           l++;
       }
       if(currsum==target) {
        int len=r-l+1;
        if(l>0 && bestarr[l-1]!=INT_MAX){
            result=min(result,len+bestarr[l-1]);
        }
       minlen=min(minlen,len);
       }
       bestarr[r]=minlen;
       r++;
          
      }
      return result==INT_MAX ?-1:result;
      
  

    }
};