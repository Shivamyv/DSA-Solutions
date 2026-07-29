class Solution {
public:

    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        long long ans=0;
        int sr=startPos[0];
        int sc=startPos[1];
        int er=homePos[0];
        int ec=homePos[1];
       while(sr<er){
         sr++;
           ans+=rowCosts[sr];
       }
       while(sr>er){
         sr--;
       ans+=rowCosts[sr];
       }
       while(sc<ec){
        sc++;
        ans+=colCosts[sc];
       }
       while(sc>ec){
        sc--;
        ans+=colCosts[sc];
       }
       return ans;
    }
};