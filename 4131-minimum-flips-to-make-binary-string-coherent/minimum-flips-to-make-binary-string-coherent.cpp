class Solution {
public:
    int minFlips(string s) {
        int  n=s.size();
        int count1=0,count0=0;
        
         for(char ch:s){
            if(ch=='1') count1++;
         }
         int ans=n;
         ans=min(count1,n-count1);
         ans=min(ans,abs(count1-1));
         if(n>1){
            
            int cost=0;
            if(s[0]=='0') cost++;
            if(s[n-1]=='0') cost++;
            for(int i=1;i<n-1;i++){
               if(s[i]=='1') cost++;
            }
            ans=min(ans,cost);
         }
    return ans;
        
    }
};