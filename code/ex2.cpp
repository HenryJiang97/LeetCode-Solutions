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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* p = root;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int digit = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            carry = digit / 10;
            ListNode* nxt = new ListNode(digit % 10);
            p->next = nxt;
            p = p->next;
            if (l1 != NULL)    l1 = l1->next;
            if (l2 != NULL)    l2 = l2->next;
        }
        return root->next;
    }
};