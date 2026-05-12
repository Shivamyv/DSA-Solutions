class Solution {
public:
 bool ispossible(int mid,vector<vector<int>>& tasks){
      for(auto &task:tasks){
        int actual=task[0];
        int minimum=task[1];
        if(minimum>mid) return false;
       mid-=actual;
      }

    return true;

 }

    int minimumEffort(vector<vector<int>>& tasks) {
     int n=tasks.size();
     int m=tasks[0].size();
     sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
          int diff1=a[1]-a[0];
          int diff2=b[1]-b[0];
          return diff1>diff2;
     });
     int ans=INT_MAX;
    int low=0,high=1e9;
    while(low<=high){
        int mid=low+(high-low)/2;
         if(ispossible(mid,tasks)){
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