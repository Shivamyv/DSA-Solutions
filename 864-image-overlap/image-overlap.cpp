class Solution {
public:
int countoverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int i,int j){
    int n=img1.size();
    int count=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            int B_i=row+i;
            int B_j=col+j;
            if(row+i < 0 || col+j<0 || row+i>=n || col+j >=n) continue;
            if(img1[row][col]==1 && img2[B_i][B_j]==1) count++;
        }
    }
    return count;
}
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
      int n=img1.size();
      int maxoverlap=0;
      for(int i=-n+1;i<n;i++){
        for(int j=-n+1;j<n;j++){
            maxoverlap=max(maxoverlap,countoverlaps(img1,img2,i,j));

        }
      }   

    return maxoverlap;

    }
};