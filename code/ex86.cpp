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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);    // < x
        ListNode* l2 = new ListNode(0);    // >= x
        ListNode* p = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p != NULL) {
            if (p->val < x) {
                p1->next = p;
                p = p->next;
                p1 = p1->next;
                p1->next = NULL;
            } else {
                p2->next = p;
                p = p->next;
                p2 = p2->next;
                p2->next = NULL;
            }
        }
        
        p1->next = l2->next;
        return l1->next;
    }
};