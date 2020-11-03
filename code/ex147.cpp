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
        ListNode* newHead = new ListNode(0);
        
        ListNode* p = head;
        while (p != NULL) {
            // Find insertion position
            ListNode* q = newHead;
            while (q->next != NULL && q->next->val < p->val) {
                q = q->next;
            }
            
            // Insert
            ListNode* nxtP = p->next;
            p->next = q->next;
            q->next = p;
            
            p = nxtP;
        }
        
        return newHead->next;
    }
};