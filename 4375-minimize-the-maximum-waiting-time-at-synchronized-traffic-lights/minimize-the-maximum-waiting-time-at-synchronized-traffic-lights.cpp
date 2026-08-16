class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
      int n=arrivalTime.size();
      int m=lights.size();
      sort(lights.begin(),lights.end());
       int ans=INT_MIN;
       int cnt=0;
       for(int i=0;i<n;i++){
         int r=arrivalTime[i] % period;
            
         if(r>=lights[m-1]){
            cnt=period-r;

         }
         
         ans=max(ans,cnt);
         

       }   
       return ans;     


    }
};