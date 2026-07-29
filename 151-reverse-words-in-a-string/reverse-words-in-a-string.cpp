class Solution {
public:
    string reverseWords(string s) {
      int n=s.size();
      reverse(s.begin(),s.end());
      int i=0,j=0;
      string ans;
     
      while(j<n){
        while(s[j]==' ') j++;
        i=j;
        while(j<n && s[j]!=' ') j++;
        reverse(s.begin()+i,s.begin()+j);
        ans+=s.substr(i,j-i)+" ";

      }
     while(ans.back()==' ') ans.pop_back();
     return ans;

       
    }
};