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
        ListNode* evenHead = new ListNode(0);
        ListNode* oddHead = new ListNode(0);
        int i = 0;
        ListNode* p = head;
        ListNode* even = evenHead;
        ListNode* odd = oddHead;
        while (p != NULL) {
            if (i % 2 == 0) {
                even->next = p;
                p = p->next;
                even = even->next;
                even->next = NULL;
            } else {
                odd->next = p;
                p = p->next;
                odd = odd->next;
                odd->next = NULL;
            }
            i++;
        }
        even->next = oddHead->next;
        return evenHead->next;
    }
};