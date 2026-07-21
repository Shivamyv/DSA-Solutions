class Solution {
public:
int f(string word1, string word2){
    int n=word1.size();
    int m=word2.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<int>curr(m+1,0),prev(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[m];
}
 
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int lcs=f(word1,word2);
        int k1=n-lcs;
        int k2=m-lcs;
        return k1+k2;
        

    }
};