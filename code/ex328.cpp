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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)    return NULL;
        ListNode* oddHead = head;    if (oddHead->next == NULL)    return oddHead;
        ListNode* evenHead = head->next;
        
        ListNode* p1 = oddHead;
        ListNode* p2 = evenHead;
        while (p1->next != NULL && p2->next != NULL) {
            p1->next = p2->next;
            p1 = p1->next;
            if (p1->next == NULL)    break;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p2->next = NULL;
        p1->next = evenHead;

        return oddHead;
    }
};