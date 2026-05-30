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
void f(TreeNode*node,vector<int>&ans){
    if(node==nullptr) return;
    if(node->left!=nullptr) {
        f(node->left,ans);

    }
    if(node->right!=nullptr){
        f(node->right,ans);
    }
    ans.push_back(node->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
         f(root,ans);
         return ans;
        
    }
};