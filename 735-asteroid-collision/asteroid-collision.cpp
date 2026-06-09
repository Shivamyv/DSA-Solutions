class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
         stack<int>st;
         for(int x:asteroids){
         bool isdestroy=false;
         
             while(!st.empty() && st.top()> 0 && x<0){
             if(st.top()<abs(x)){
                st.pop();

             }   
             else if(st.top()==abs(x)){
                st.pop();
                isdestroy=true;
                break;
             }
             else{
                isdestroy=true;
                break;
             }
             }
             if(!isdestroy) st.push(x);
             
             }
             vector<int>ans;
             while(!st.empty()){
                 ans.push_back(st.top());
                 st.pop();
             }

        
        reverse(ans.begin(),ans.end());
        return ans;

    }
};