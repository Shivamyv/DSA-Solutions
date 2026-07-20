class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int rows=grid.size();
         int cols=grid[0].size();
         int n=rows*cols;
         k=k%n;
         vector<vector<int>>ans(rows,vector<int>(cols));
         for(int i=0;i<n;i++){
            int row=i/cols;
            int col=i%cols;
            int newindex=(i+k)%n;
            int nrow=newindex/cols;
            int ncol=newindex%cols;
            ans[nrow][ncol]=grid[row][col];
         }

       return ans;  
         

    }
};