class Solution {
public:
bool f(int i,int j,string &s){
   if(i>=j) return true;
   if(s[i]==s[j]){
     return  f(i+1,j-1,s);
   }
   return false;

}
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=INT_MIN;
         int sp=0;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(f(i,j,s)==true){
                if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    sp=i;
                }
               }
            }
         }
        
        return s.substr(sp,maxlen);
        
    }
};