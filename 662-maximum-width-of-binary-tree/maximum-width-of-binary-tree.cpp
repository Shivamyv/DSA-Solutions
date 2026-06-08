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
    int widthOfBinaryTree(TreeNode* root) {
      if(root==nullptr) return 0;
        long long ans=0;

      queue<pair<TreeNode*,long long>>q;
      q.push({root,0});
        
      while(!q.empty()){
        int size=q.size();
         long long first=0;
         long long last=0;
        long long minm=q.front().second;
         for(int i=0;i<size;i++){
            
        long long currid=q.front().second-minm;
        TreeNode*node=q.front().first;
          q.pop();

          if(i==0) first=currid;
         if(i==size-1) last=currid;
         if(node->left){
            q.push({node->left,currid*2+1});
         }
         if(node->right){
            q.push({node->right,currid*2+2});
         }

         }

       ans=max(ans,last-first+1);

      }
    return ans;

    }
};