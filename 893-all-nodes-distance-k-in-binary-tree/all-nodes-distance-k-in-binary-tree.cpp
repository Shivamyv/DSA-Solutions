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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         
        unordered_map<TreeNode*,TreeNode*>parentnode;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                parentnode[node->left]=node;
                q.push(node->left);

            }
            if(node->right){
                parentnode[node->right]=node;
                q.push(node->right);
            }

        }
        int count=0;
        unordered_map<TreeNode*,bool>vis;

        q.push(target);
        vis[target]=true;

        while(!q.empty()){
            int size=q.size();
           if(count==k){
            break;
           }
            count++;
           
            for(int i=0;i<size;i++){
               TreeNode*node=q.front();
            q.pop();

               if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;

               }

               if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
               }
              if(parentnode.find(node)!=parentnode.end() && !vis[parentnode[node]]){
                    vis[parentnode[node]]=true;
                    q.push(parentnode[node]);
              }

            }

           }
          vector<int>ans;
         while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
         }

        return ans; 


    }
};