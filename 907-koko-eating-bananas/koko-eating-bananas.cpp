class Solution {
public:
bool f(vector<int>& piles, int h,int k){
     long long hours=0;
    for(int pile:piles){
        hours+=(pile+k-1)/k;

    }
  return hours<=h;


}
    int minEatingSpeed(vector<int>& piles, int h) {
     int n=piles.size();
    
     int low=1;
     int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(f(piles,h,mid)){
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