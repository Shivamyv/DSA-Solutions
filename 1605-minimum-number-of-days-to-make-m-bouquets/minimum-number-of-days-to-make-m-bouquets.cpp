class Solution {
public:
  bool f(vector<int>& bloomDay, int m, int k,int days){
     int n=bloomDay.size();
      int cnt=0;
      int bouqets=0;
     for(int i=0;i<n;i++){
        if(bloomDay[i]<=days){
            cnt++;
            if(cnt==k) {
                bouqets++;
            cnt=0;
            }

        }
        else{
            cnt=0;
        }
     }
     return bouqets>=m;
      
    
  }



    int minDays(vector<int>& bloomDay, int m, int k) {
     
     int low=1;

     int high=*max_element(bloomDay.begin(),bloomDay.end());
     long long ans=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(f(bloomDay,m,k,mid)){
         ans=mid;
         high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return ans;

    }
};