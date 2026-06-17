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
    int ans = 0;

    struct NodeInfo {
        int mn;
        int mx;
        int sum;

        NodeInfo(int mn, int mx, int sum)
            : mn(mn), mx(mx), sum(sum) {}
    };

    NodeInfo dfs(TreeNode* root) {
        if (!root)
            return NodeInfo(INT_MAX, INT_MIN, 0);

        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);

        if (left.mx < root->val && root->val < right.mn) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return NodeInfo(
                min(left.mn, root->val),
                max(right.mx, root->val),
                currSum
            );
        }

        return NodeInfo(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};