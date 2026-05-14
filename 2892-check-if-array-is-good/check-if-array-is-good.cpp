class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int max=*max_element(nums.begin(),nums.end());
        if(n!=max+1) return false;
        vector<int>freq(max+1,0);
        for(int x:nums){
            if(x<1 || x>max) return false;
            freq[x]++;
        }
        for(int i=1;i<max;i++){
            if(freq[i]!=1) return false;
        }

    return freq[max]==2;

    }
};