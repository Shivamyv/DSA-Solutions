class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
       
    for(int i=num1;i<=num2;i++){
       string sh=to_string(i);
      for(int j=1;j<sh.size()-1;j++){
        int curr=sh[j]-'0';
        int prev=sh[j-1]-'0';
        int next=sh[j+1]-'0';
        if(curr>prev && curr>next || curr<prev&& curr<next)
         cnt++;



      }
    }

    return cnt;

    }
};