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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                p->next = p2;
                p2 = p2->next;
            } else if (p2 == NULL) {
                p->next = p1;
                p1 = p1->next;
            } else if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        return head->next;
    }
};