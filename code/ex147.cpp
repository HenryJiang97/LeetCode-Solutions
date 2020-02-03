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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)    return head;
        ListNode* nHead = new ListNode(INT_MIN);
        nHead->next = head;
        ListNode* p = head->next;
        ListNode* prev = head;
        while (p != NULL) {
            ListNode* nxt = p->next;
            ListNode* h = nHead;
            bool ifInserted = 0;
            while (h->next != p) {
                if (p->val <= h->next->val) {    // Insert
                    p->next = h->next;
                    h->next = p;
                    prev->next = nxt;
                    ifInserted = 1;
                    break;
                }
                h = h->next;
            }
            if (!ifInserted)    prev = p;
            p = nxt;
        }
        return nHead->next;
    }
};