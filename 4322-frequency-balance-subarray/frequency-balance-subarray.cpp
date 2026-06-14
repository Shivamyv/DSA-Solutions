class Solution {
public:
    int getLength(vector<int>& nums) {
       int n=nums.size();
       int ans=1;
       for(int i=0;i<n;i++){
     unordered_map<int,int>freq;
     unordered_map<int,int>cnt;
     int maxfreq=0;
      for(int j=i;j<n;j++){
        int x=nums[j];
        int oldfreq=freq[x];
        if(oldfreq>0){
            cnt[oldfreq]--;
            if(cnt[oldfreq]==0){
                cnt.erase(oldfreq);
            }
        }
        freq[x]++;
        int newfreq=freq[x];
        cnt[newfreq]++;
        maxfreq=max(maxfreq,newfreq);
        int len=j-i+1;
        bool valid=false;
        if(len==1) {
            valid=true;
        }
        else if(freq.size()==1) valid=true;
        else{
            if(maxfreq%2==0 && cnt.size()==2 && cnt.count(maxfreq)&&
            cnt.count(maxfreq/2)) valid=true;
        }
      
      if(valid)
       ans=max(ans,len);
      }
       }  

     return ans;
     

    }
};