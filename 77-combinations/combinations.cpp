class Solution {
public:
void f(int i,int n,int k,vector<vector<int>>&ans, vector<int>&curr){
    
if(curr.size()==k){
    ans.push_back(curr);
    return;
}
    
    for(int j=i;j<=n;j++){
        curr.push_back(j);
        f(j+1,n,k,ans,curr);
        curr.pop_back();

    }

}
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>curr;

         f(1,n,k,ans,curr);
        return ans;
    }
};