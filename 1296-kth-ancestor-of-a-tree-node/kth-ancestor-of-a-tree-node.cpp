class TreeAncestor {
public:
     int row;
     int cols;
      vector<vector<int>>ancestortable;

    TreeAncestor(int n, vector<int>& parent) {
        row=n;
        cols=log2(n)+1; 
        ancestortable.resize(row,vector<int>(cols,-1));
        for(int node=0;node<n;node++){
            ancestortable[node][0]=parent[node];
        } 
      for(int j=1;j<cols;j++){
        for(int node=0;node<n;node++){
            if(ancestortable[node][j-1]!=-1){
                ancestortable[node][j]=ancestortable[ancestortable[node][j-1]][j-1];
            }
        }
      }

    }
    
    int getKthAncestor(int node, int k) {
      for(int j=0;j<cols;j++){
        if(k&(1<<j)){
            node=ancestortable[node][j];
            if(node==-1) return -1;
        }

      }   

   return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */