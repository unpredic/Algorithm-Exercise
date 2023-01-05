/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre = NULL, *head = NULL;
    void dfs(Node* cur) {
        if (cur == NULL) return;
        dfs(cur->left);
        if (pre == NULL) head = cur; // pre 为null, 找到头节点
        else { // 存在pre, 将pre与cur左右互联
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};