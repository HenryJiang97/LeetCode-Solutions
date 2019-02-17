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
        // No item in the list
        if (head == NULL)
            return NULL;
        
        // One item in the list
        if (head->next == NULL) {
            return head;
        }
        
        
        // Two or more items in the list
        ListNode*p = head->next;
        head->next = NULL;
        ListNode*v = head;
        
        
        while (p->next != NULL) {
            ListNode* q = p;
            p = p->next;
            
            q->next = v;
            v = q;
        }
        p->next = v;
        
        
        return p;
    }
};