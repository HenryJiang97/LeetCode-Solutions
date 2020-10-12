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
        
        ListNode* prev = dummy;
        ListNode* p = dummy->next;
        while (p != NULL) {
            ListNode* nxt = p;
            if (p->next == NULL) {
                prev->next = p;
                p->next = NULL;
                break;
            }
            p = p->next;
            ListNode* nnxt = p;
            p = p->next;
            
            // Swap
            prev->next = nnxt;
            nnxt->next = nxt;
            prev = nxt;
            prev->next = NULL;
        }
        
        return dummy->next;
    }
};