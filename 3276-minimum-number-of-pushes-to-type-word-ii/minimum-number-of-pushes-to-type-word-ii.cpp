class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
       vector<int>freq(26,0);
       for(char ch:word){
        freq[ch-'a']++;
       }
       sort(freq.begin(),freq.end(),greater<int>());
       int ans=0;
       for(int i=0;i<26;i++){
         int mpp=freq[i];
         int pres=i/8+1;
         ans+=mpp*pres;

       }
       
         

      return ans;
    }
};