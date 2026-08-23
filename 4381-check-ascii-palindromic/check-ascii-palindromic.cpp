class Solution {
public:
string f(int n){
    string ans="";
    if(n==0) return "0";
       for(int i=0;i<8;i++){
     
        int q=n%2;
        ans+=char(q+'0');
        n/=2;
     } 
     reverse(ans.begin(),ans.end());
     return ans;


}
bool ispalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    bool isPalindromic(string s) {

        int n=s.size();
        
        string bit="";

        for(int i=0;i<n;i++){
            int cnt=s[i];
            bit+=f(cnt);


        }
        if(ispalindrome(bit)) return true;
        return false;
    }
};