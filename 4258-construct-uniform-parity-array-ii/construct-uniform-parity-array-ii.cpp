class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     int n=nums1.size();
     int odd=INT_MAX;
    for(int i=0;i<n;i++){
       
        if(nums1[i]%2==1 && nums1[i]<odd){
          odd=nums1[i];
        }

    }
    if(odd==INT_MAX) return true;
    for(int i=0;i<n;i++){
        if(nums1[i]<odd) return false;
    }
   return true;

    }
};