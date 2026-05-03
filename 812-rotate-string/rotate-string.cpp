class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        for(int i=0;i<s.length();i++){
            string roated=s.substr(i)+s.substr(0,i);
            if(roated==goal) return true;
        }
        return false;
    }
};