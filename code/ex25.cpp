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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        for (ListNode* p = head; p != NULL; p = p->next)
            len++;
        
        ListNode* p = head;
        ListNode* newHead = new ListNode(0);
        ListNode* newP = newHead;
        for (int i = 0; i + k - 1 < len; i += k) {
            vector<ListNode*> h = reverse(p, k);
            newP->next = h[0];
            newP = h[1];
            p = h[2];
        }
        
        newP->next = p;

        return newHead->next;
    }
    
private:
    // Reverse a subLinkedlist with length of k
    vector<ListNode*> reverse(ListNode* p, int k) {    // Return {head, tail, nextStart}
        ListNode* tail = p;
        ListNode* cur = p->next;
        ListNode* prev = p;
        
        for (int i = 1; i < k; i++) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        return {prev, tail, cur};
    }
};