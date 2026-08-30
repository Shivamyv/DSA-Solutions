class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int remove=-1;remove<n;remove++){
        vector<int>arr;

        
        for(int i=0;i<n;i++){
            if(remove!=i){
                arr.push_back(nums[i]);
            }
        }
       int m=arr.size();
       if(m<2) continue;
       vector<int>prefix(m);
       prefix[0]=arr[0];
       for(int i=1;i<m;i++){
        prefix[i]=gcd(prefix[i-1],arr[i]);
       }
       vector<int>suffix(m);
       suffix[m-1]=arr[m-1];
       for(int i=m-2;i>=0;i--){
        suffix[i]=gcd(suffix[i+1],arr[i]);

       }
       int cnt=0;
     for(int i=0;i<m-1;i++){
       int leftgcd=prefix[i];
        int rightgcd=suffix[i+1];
        if(leftgcd==rightgcd) cnt++;
     }
      ans=max(ans,cnt);


        }
      
      return ans;


    }
};