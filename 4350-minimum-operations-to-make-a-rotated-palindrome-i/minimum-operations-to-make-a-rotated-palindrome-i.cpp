class Solution {
public:
    int minOperations(string s) {
       int n=s.size();
       int ans=INT_MAX;
       string k=s;
       for(int i=0;i<n;i++){
        int cost=i;
        for(int l=0;l<n/2;l++){
            int r=n-1-l;
            char a=k[(i+l)%n];
            char b=k[(i+r)%n];
            int atob=(b-a+26)%26;
            int btoa=(a-b+26)%26;
            cost+=min(atob,btoa);

        }
        ans=min(ans,cost);

       }
       return ans;

        
    }
};