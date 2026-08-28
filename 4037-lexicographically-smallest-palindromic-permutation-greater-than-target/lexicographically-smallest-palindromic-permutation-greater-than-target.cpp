class Solution {
public:
   string result="";
   char midchar='$';
    int half=0;

   bool f(int i,string& curr,string s, string& target,bool greater,  vector<int>&count){
      int n=s.length();
      if(i==half){
        string candidate=curr;
        string righthalf=candidate;
        reverse(righthalf.begin(),righthalf.end());
        if(midchar!='$')
            candidate+=midchar;
            candidate+=righthalf;
            if(candidate>target){
                result=candidate;
                return true;
            
        }
            return false;

        }
         for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (f(i+1, curr,s, target,isGreater,count))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
      }

   
    string lexPalindromicPermutation(string s, string target) {
       int n=s.size();
       
       vector<int>count(26,0);
       for(char ch:s){
         count[ch-'a']++;

       }

       int oddcount=0;
       for(int i=0;i<26;i++){
        if(count[i]%2==1) {
        oddcount++;
        midchar=i+'a';
       }
       }
        if(oddcount>1) return "";

        for(int c=0;c<26;c++){
            count[c]/=2;
        }

        half=n/2;
        string curr;
       f(0,curr,s,target,false,count);
      return result;


    }
};