/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r=p->val;

        int c=q->val;
       int curr=root->val;

       if(curr<r && curr<c){
       return lowestCommonAncestor(root->right,p,q);
       }
       else if(curr>r &&  curr>c){
       return lowestCommonAncestor(root->left,p,q);
       }

     return root;

    }
};