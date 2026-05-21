class Solution {
public:
   bool bfs(vector<vector<int>>& rooms, vector<int>&vis){
    int V=rooms.size();
     queue<int>q;
     int node=0;
     q.push(node);
     vis[node]=1;
     while(!q.empty()){
        auto nodes=q.front();
        q.pop();
        for(auto it:rooms[nodes]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
     }
     for(auto it:vis){
        if(!it){
            return false;
        }
     }

    return true;

   }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V=rooms.size();
        vector<int>vis(V,0);
        return bfs(rooms,vis);

    }
};