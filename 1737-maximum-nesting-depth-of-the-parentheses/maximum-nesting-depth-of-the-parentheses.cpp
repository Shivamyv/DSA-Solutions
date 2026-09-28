class Solution {
public:
    int maxDepth(string s) {
    int n=s.size();
     int leftchar=0;
     int rightchar=0;
     int ans=INT_MIN;
     for(int i=0;i<n;i++){
        if(s[i]=='(') leftchar++;
        ans=max(ans,leftchar);
         if(s[i]==')') leftchar--;
     }
        return ans;
    }
};