class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();  
       if(nums.empty()) return 0;
       unordered_set<int>st(nums.begin(),nums.end());
      int cnt=1;
      for(int num:st){
        if(st.find(num-1)==st.end()){
            int current=num;
            int len=1;
            while(st.find(current+1)!=st.end()){
                current++;
                len++;
            }
            cnt=max(cnt,len);
        }
      }
      return cnt;
   
    }
};