class Solution {
public:
  bool check(int i,int j,string &s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
    i++;
    j--;
    }
    return true;

  }

  void f(int i,string &s, vector<vector<string>> &ans,vector<string>&path){
    int n=s.size();
    if(i==n) {
     ans.push_back(path);
        
    } 
    for(int j=i;j<n;j++){
       if(check(i,j,s)){
      
              path.push_back(s.substr(i,j-i+1));
                f(j+1,s,ans,path);
                path.pop_back();

    }

  }
  }

    vector<vector<string>> partition(string s) {
       int n=s.size();
       vector<vector<string>>ans;
       vector<string>path;
        f(0,s,ans,path);
        return ans;


    }
};