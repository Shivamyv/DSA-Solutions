class Solution {
public:
    int minimumPushes(string word) {
    int n=word.size();
   
     int ans=0;
      int push=1;

     while(n>0){
     int take=min(8,n);
     ans+=take*push;
     n-=take;
     push++;

    
     }


    return ans;
   
    }
};