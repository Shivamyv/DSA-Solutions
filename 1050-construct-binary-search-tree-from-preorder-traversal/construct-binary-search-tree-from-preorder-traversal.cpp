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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index=0;
    return f(preorder,INT_MAX,index);

    }
 TreeNode* f(vector<int>& preorder,int bound,int &index){
    int n=preorder.size();
     if(index==n || preorder[index]>bound) return nullptr;

    TreeNode*root=new TreeNode(preorder[index++]);
    root->left=f(preorder,root->val,index);
    root->right=f(preorder,bound,index);

    return root;

  }


};