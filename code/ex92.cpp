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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* p = dummy;
        for (int i = 0; i < m - 1; i++)    p = p->next;
        
        // Reverse the interval [m, n]
        ListNode* h = NULL;
        ListNode* t = NULL;
        ListNode* q = p->next;
        for (int i = 0; i < n - m + 1; i++) {
            ListNode* nxt = q->next;
            q->next = h;
            h = q;
            if (t == NULL)    t = h;
            q = nxt;
        }
        
        t->next = q;
        p->next = h;
        return dummy->next;
    }
};