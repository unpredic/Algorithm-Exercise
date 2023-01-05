/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* pre = NULL, *cur = head;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};