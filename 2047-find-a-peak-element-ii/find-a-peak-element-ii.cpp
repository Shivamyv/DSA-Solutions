class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
     int n=mat.size();
     int m=mat[0].size();
   vector<int>ans;
     int dr[]={-1,0,+1,0};
     int dc[]={0,+1,0,-1};
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool peak =true;
           for(int k=0;k<4;k++){
             int nrow=i+dr[k];
             int ncol=j+dc[k];
             if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && mat[nrow][ncol]>=mat[i][j]){
                peak=false;
                break;
                
             }
             

           }
          
           if(peak)
     return {i,j};


        }
     }
     

   return ans;

    }
};