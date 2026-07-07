class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mpp;
        int r=1;
        for(int x:temp){
            if(mpp.find(x)==mpp.end()){
                mpp[x]=r;
                r++;

            }
        }
     vector<int>ans;
     for(int x:arr){
        ans.push_back(mpp[x]);
     }
       return ans;  

    }
};