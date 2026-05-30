class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
      set<char>ste{'@', '!', '$', '#'};
       unordered_set<char>st(password.begin(),password.end());
      for(char ch:st){
          
            if(islower(ch)) ans+=1;
             else if(isupper(ch)) ans+=2;
            else if(ste.find(ch)!=ste.end()) ans+=5;
            else{
                ans+=3;
            }
        }
       
    return ans;

    }
};