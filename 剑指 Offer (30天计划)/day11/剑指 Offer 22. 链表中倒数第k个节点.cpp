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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head, *cur = head;
        while (cur && -- k ) {
            cur = cur->next;
        }
        while (cur->next) {
            pre = pre->next;
            cur = cur->next;
        }
        return pre;
    }
};