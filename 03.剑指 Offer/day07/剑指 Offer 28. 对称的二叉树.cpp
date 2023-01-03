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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* p, TreeNode* q) {
        // 左子树或右子树不存在：false
        // 左右子树都不存在：true
        if (!p || !q) return !p && !q;
        // 左右子树都存在
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};