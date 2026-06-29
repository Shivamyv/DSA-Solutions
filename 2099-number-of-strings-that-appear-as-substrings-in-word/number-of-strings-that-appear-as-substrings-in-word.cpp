class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(string sh:patterns){
            if(word.find(sh)!= string ::npos){
                cnt++;
            }
        }
        return cnt;
    }
};