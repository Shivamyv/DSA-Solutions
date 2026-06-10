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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int m=inorder.size();
      int n=preorder.size();
       unordered_map<int,int>mpp;
       for(int i=0;i<n;i++){
        mpp[inorder[i]]=i;
       }
        return build(preorder,0,n-1,inorder,0,m-1,mpp);

       }    
           TreeNode* build(vector<int>& preorder,int prestart,int prend, vector<int>& inorder,
           int instart,int inend,unordered_map<int,int>&mpp){
          
             if(prestart>prend || instart>inend) return nullptr;
               TreeNode*root=new TreeNode(preorder[prestart]);
               int inroot=mpp[root->val];
               int dist=inroot-instart;
                root->left = build(preorder, prestart + 1, prestart + dist,
                               inorder, instart, inroot - 1, mpp);

           
              root->right = build(preorder, prestart + dist + 1, prend,
                                inorder, inroot + 1, inend, mpp);
           
           
           return root;
      

    }
};