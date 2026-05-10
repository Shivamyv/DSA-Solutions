class Solution {
public:
    long long minArraySum(vector<int>& nums) {
    int n=nums.size();
   unordered_map<int,int>mpp;
   for(auto it:nums){
     mpp[it]++;
   }
   for(auto &x:nums){
    vector<int>factorial;
   for(int i=1;i*i<=x;i++){
    if(x%i!=0) continue;
    if(mpp[i]) {
        x=i; 
        break;
    }
    factorial.push_back(x/i);
   }
    while(!factorial.empty()){
        int y=factorial.back();
        factorial.pop_back();
        if(mpp[y]){
           x= min(x,y);
           break;
        }
    }
   }
   return accumulate(nums.begin(),nums.end(),0LL);


    }
};