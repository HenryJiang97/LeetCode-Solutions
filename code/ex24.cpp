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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next != NULL && p->next->next != NULL) {
            ListNode* n1 = p->next;
            ListNode* n2 = n1->next;
            n1->next = n2->next;
            p->next = n2;
            n2->next = n1;
            p = n1;
        }
        return dummy->next;
    }
};