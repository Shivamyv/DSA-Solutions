class Solution {
public:
string ans="";
bool f(int i,string s, string target,bool greater,string curr, vector<int>&count){
    if(i==target.length()){
        if(greater){
            ans=curr;
            return true;
        }
        return false;
    }
   for(char ch='a';ch<='z';ch++){
    if(count[ch-'a']==0) continue;
    if(greater==false &&ch<target[i]) continue;
    curr.push_back(ch);
    count[ch-'a']--;
    bool isgreater=greater||ch>target[i];
    if(f(i+1,s,target,isgreater,curr,count)){
        return true;
    }
    curr.pop_back();
    count[ch-'a']++;

   }

  return false;


}
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
         vector<int>count(26,0);
         for(char ch:s){
            count[ch-'a']++;
         }
            string curr;
            f(0,s,target,false,curr,count);
            return ans;
    }
};