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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode* p = head;
        
        while (p != NULL) {
            ListNode* cur = p;
            ListNode* i = dummy;
            while (i->next != NULL && i->next->val < cur->val)    i = i->next;
            p = p->next;
            
            if (i->next != cur) {
                cur->next = i->next;
                i->next = cur;
            }
        }
        
        return dummy->next;
    }
};