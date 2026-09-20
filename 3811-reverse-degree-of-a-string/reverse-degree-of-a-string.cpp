class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int ind=i+1;
            int reverse='z'-s[i]+1;
            sum+=ind*reverse;
        }
        return sum;
    }
};