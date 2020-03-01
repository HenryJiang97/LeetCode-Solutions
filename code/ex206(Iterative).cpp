// Iterative

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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while (head != NULL) {
            ListNode* p = new ListNode(head->val);
            p->next = newHead;
            newHead = p;
            head = head->next;
        }
        return newHead;
    }
};