// 暴力写法
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
    vector<int> path;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        path.push_back(root->val);
        dfs(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return path[path.size() - k];
    }
};
// 中序遍历倒序优化
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
    int res, n;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->right);
        n -- ;
        if (n == 0) res = root->val;
        dfs(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        n = k;
        dfs(root);
        return res;
    }
};