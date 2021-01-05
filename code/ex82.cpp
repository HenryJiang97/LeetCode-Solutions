/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* p = head;
        while (p != NULL) {
            ListNode* nxt = p->next;
            while (nxt != NULL && nxt->val == p->val)    nxt = nxt->next;
            if (nxt != p->next) {
                prev->next = nxt;
                p = nxt;
            } else {
                prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};