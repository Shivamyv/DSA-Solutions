class Solution {
public:
// bool lexico(string ans,string prev){
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<prev.siz();j++){
//         if(ans[i]-'0' < ans[j]-'0') return true;
//     }
//     }
//     return false;

// }
    string shortestBeautifulSubstring(string s, int k) {
       int n=s.size();
       string ans="";
      int l=0,r=0;
      int cnt1=0;
      while(r<n){
        if(s[r]=='1') cnt1++;
        while(cnt1>k || s[l]=='0'){
            if(s[l]=='1') {
                cnt1--;
            }

            l++;
        }
       if(cnt1==k){
        string temp=s.substr(l,r-l+1);
         if(ans.empty() || r-l+1<ans.length() || r-l+1 ==ans.length() && temp<ans){
            ans=temp;
         }
       }
      
        r++;

      }
      return ans;

         
    }
};