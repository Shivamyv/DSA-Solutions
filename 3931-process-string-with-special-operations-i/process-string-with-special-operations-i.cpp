class Solution {
public:
bool f(char ch){
    for(int i='a';i<='z';i++){
        if(ch==i) return true;
    }
    return false;
}
    string processStr(string s) {
        int n=s.length();
      string ans="";
      for(int i=0;i<n;i++){
        if(f(s[i])){
            ans.push_back(s[i]);
        }
        else if(s[i]=='*' && !ans.empty()){
            ans.pop_back();
            
        }
        else if(s[i]=='#'){
            ans.append(ans);
        }
        else if(s[i]=='%'){
            reverse(ans.begin(),ans.end());
        }
      }
     return ans;

    }
};