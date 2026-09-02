// class Solution {
// public:
//     using VB = vector<bool>;
//     using VVB = vector<VB>;
//     using VVVB = vector<VVB>;
//     using VVVVB = vector<VVVB>;

//    int dr[4]={-1,0,+1,0};
//    int dc[4]={0,+1,0,-1};
//    struct state{
//     int row;
//     int col;
//     int energyleft;
//     int bitmask;

//    };
//       int minMoves(vector<string>& classroom, int energy) {
//      int n=classroom.size();
//      int m=classroom[0].size();
//     int maxenergy=energy;
//       int startrow=0;
//       int startcol=0;
//       int littercount=0;
//      int litterbit[20][20];
//       for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             litterbit[i][j]=-1;
//             if(classroom[i][j]=='S'){
//                 startrow=i;
//                 startcol=j;

//             }
//            else if(classroom[i][j]=='L'){
//             litterbit[i][j]=littercount;
//             littercount++;

//            }
//         }
//       }
//        int allcollected = (1 << littercount) - 1;
//         if (littercount == 0) 
//             return 0;
//      VVVVB seen(n,VVVB(m,VVB(maxenergy+1,VB(1 << littercount,false))));


//       queue<state>q;
//       q.push({startrow,startcol,maxenergy,0});
//       seen[startrow][startcol][maxenergy][0]=true;
//       int moves=0;
//       while(!q.empty()){
//         int currsize=q.size();
//         while(currsize--){
//             state it=q.front();
//             q.pop();
//             if(it.bitmask==allcollected) return moves;
//             if(it.energyleft==0) continue;
//             for(int i=0;i<4;i++){
//                 int nrow=dr[i]+it.row;
//                 int ncol=dr[i]+it.col;
//                 if(nrow<0 || ncol<0 || nrow>=n || ncol>=m) continue;
//                 char cell=classroom[nrow][ncol];
//                 if(cell=='X') continue;
//                   int nextenergy = it.energyleft - 1;
//                     int nextmask = it.bitmask;
//                     if(cell=='R'){
//                         nextenergy=maxenergy;
//                     }
//                     else if (cell == 'L') {
//                         nextmask |= (1 << litterbit[nrow][ncol]);
//                     }
//                      if (!seen[nrow][ncol][nextenergy][nextmask]) {
//                         seen[nrow][ncol][nextenergy][nextmask] = true;
//                         q.push({nrow, ncol, nextenergy, nextmask});
//                      }          
//         }
//       }
      
//         moves++;
//       }
//       return -1;
   

//     }
// };
//
class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    struct State {
            int row;
            int col;
            int energyLeft;
            int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;

        int litterBit[20][20]; //which bit position does this litter represent
        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0) 
            return 0;

        VVVVB seen(m, VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        

        queue<State> que;
        que.push({startRow, startCol, maxEnergy, 0});
        seen[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;

        while (!que.empty()) {
            int currSize = que.size();

            while (currSize--) {
                State current = que.front();
                que.pop();

                if (current.collectedMask == allCollected) 
                    return moves;
                if (current.energyLeft == 0) 
                    continue;

                for (auto& dir : directions) {
                    int nextRow = current.row + dir[0];
                    int nextCol = current.col + dir[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) 
                        continue;

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') 
                        continue;

                    int nextEnergy = current.energyLeft - 1;
                    int nextMask   = current.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    } else if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if (!seen[nextRow][nextCol][nextEnergy][nextMask]) {
                        seen[nextRow][nextCol][nextEnergy][nextMask] = true;
                        que.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};






