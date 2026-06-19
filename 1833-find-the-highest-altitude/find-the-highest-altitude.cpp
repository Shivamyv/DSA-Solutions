class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
       int sum=0;
       int maxi=0;
       for(int x:gain){
        sum+=x;
        maxi=max(maxi,sum);
       }
       return maxi;
       
    }
};