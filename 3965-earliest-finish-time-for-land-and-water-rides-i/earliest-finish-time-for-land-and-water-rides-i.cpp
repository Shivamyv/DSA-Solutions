class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    
       int n=landStartTime.size();
       int m=waterStartTime.size();
       int ans=INT_MAX;
       for(int i=0;i<n;i++){
         int starttime=landStartTime[i]+landDuration[i];
         for(int j=0;j<m;j++){
            int start=max(starttime,waterStartTime[j]);
            int finish=start+waterDuration[j];

         
         ans=min(ans,finish);
       }
       }
  for(int i=0;i<m;i++){
    int starttime=waterStartTime[i]+waterDuration[i];
    for(int j=0;j<n;j++){
        int start=max(starttime,landStartTime[j]);
        int finish=start+landDuration[j];
        ans=min(ans,finish);
    }
  }

   return ans;

    }
};