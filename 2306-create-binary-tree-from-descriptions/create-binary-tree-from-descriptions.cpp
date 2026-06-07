/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
          int n=descriptions.size();
         
          unordered_map<int,TreeNode*>mpp;
          unordered_set<int>st;
         for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
          if(mpp.find(parent)==mpp.end()){
            mpp[parent]=new TreeNode(parent);
          }
          if(mpp.find(child)==mpp.end()){
            mpp[child]=new TreeNode(child);

          }
          if(isleft){
            mpp[parent]->left=mpp[child];
          }
          else{
            mpp[parent]->right=mpp[child];
          }
          st.insert(child);

         }
         for(auto &it:mpp){
            if(st.find(it.first)==st.end()){
                return it.second;
            }
         }



          

      return nullptr;

    }
};