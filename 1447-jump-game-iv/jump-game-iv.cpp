class Solution {
public:
    int bfs(vector<int>&arr,int start){
        int n=arr.size();
       if(n==1) return 0;
        unordered_map<int,vector<int>>mpp;
       for(int i=0;i<n;i++){
        mpp[arr[i]].push_back(i);
       }
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[start]=1;
        while(!q.empty()){
            auto [node,cnt]=q.front();
            q.pop();
           if(node==n-1) return cnt;
          int forward=node+1;
          if(forward<n && vis[forward]==0){
            q.push({forward,cnt+1});
            vis[forward]=1;
           
          }
          int backward=node-1;
          if(backward >=0 && vis[backward]==0){
            q.push({backward,cnt+1});
            vis[backward]=1;
          }
           for(auto it:mpp[arr[node]]){
            if(vis[it]==0){
                q.push({it,cnt+1});
            }
           }

        mpp[arr[node]].clear();

        }
        return -1;

    }
    int minJumps(vector<int>& arr) {
    int n=arr.size();
   return bfs(arr,0);

    }
};
