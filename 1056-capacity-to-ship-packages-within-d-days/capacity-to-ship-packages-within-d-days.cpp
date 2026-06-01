class Solution {
public:
    bool possible(vector<int>& weights, int days,int capacity){
      int n=weights.size();
      int cnt=1;
      int sum=0;
      for(int i=0;i<n;i++){
       if(sum+weights[i]<=capacity){
          sum+=weights[i];
       }
       else{
        cnt++;
        sum=weights[i];
       }
      }
      return cnt<=days;
     

    }
    int shipWithinDays(vector<int>& weights, int days) {
     int n=weights.size();
     int low=*max_element(weights.begin(),weights.end());
     int high=accumulate(weights.begin(),weights.end(),0);
    
     while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(weights,days,mid)){
          
            high=mid-1;
        }
        else{
            low=mid+1;
        }


     }
     return low;
        
    }
};