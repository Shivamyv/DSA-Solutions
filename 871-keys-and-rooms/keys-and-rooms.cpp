class Solution {
public:
   bool bfs(vector<vector<int>>& rooms){
     int V=rooms.size();
     vector<int>vis(V,0);

     queue<int>q;
     q.push(0);
     vis[0]=1;
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
       
        return bfs(rooms);

    }
};