// 方法一：哈希表
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* cur = head;
        unordered_map<Node*, Node*> umap;
        while (cur != NULL) {
            umap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur != NULL) {
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }
};

// 方法二：原地拼接+拆分
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* cur = head;
        while (cur != NULL) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        cur = head;
        while (cur != NULL) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head->next;
        Node *pre = head, *res = head->next;
        while (cur->next != NULL) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = NULL;
        return res;
    }
};