class Solution {
public:
 bool bfs(vector<int>&arr,int start){
    int n=arr.size();
     queue<int>q;
     vector<int>vis(n,0);
     q.push(start);
     vis[start]=1;
     while(!q.empty()){
        auto node= q.front();
        q.pop();
        if(arr[node]==0) return true;

        int forward=arr[node]+node;
        if( forward <n && vis[forward]==0){
            q.push(forward);
            vis[forward]=1;

        }
        int backward=node-arr[node];
        if(backward>=0 && vis[backward]==0){
            q.push(backward);
            vis[backward]=1;
        }
          
     }

   return false;


 }


    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
       if(bfs(arr,start)) return true;

     return false;
    }
};