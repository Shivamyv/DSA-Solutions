class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
       
            int i=0,j=0;
            int maxlen=INT_MIN;
            while(i<n){
                mpp[s[i]]++;
                while(mpp[s[i]]>2){
                    mpp[s[j]]--;
                    j++;

                }
                maxlen=max(maxlen,i-j+1);
                i++;

               
            }

        
           
        
        return maxlen;

    }
};