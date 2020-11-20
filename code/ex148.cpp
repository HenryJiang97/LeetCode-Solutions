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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)    return head;
        
        // Find the head of two half of the linkedlist
        ListNode* first = head;    ListNode* second = head;
        int len = 0;
        for (ListNode* p = head; p != NULL; p = p->next)    len++;
        for (int i = 0; i < len / 2 - 1; i++)    second = second->next;
        ListNode* dummy = second;    second = second->next;    dummy->next = NULL;
        
        // Divide
        ListNode* sorted1 = sortList(first);
        ListNode* sorted2 = sortList(second);
        
        // Conquer
        ListNode* sorted = new ListNode(0);
        ListNode* p = sorted;    ListNode* p1 = sorted1;    ListNode* p2 = sorted2;
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
        
        return sorted->next;
    }
};