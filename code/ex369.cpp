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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> stk;
        for (ListNode* p = head; p != NULL; p = p->next) {
            stk.push(p);
        }
        
        int carry = 1;
        while (!stk.empty()) {
            stk.top()->val += carry;
            carry = 0;
            if (stk.top()->val == 10) {
                stk.top()->val = 0;
                carry = 1;
            } else {
                break;
            }
            stk.pop();
        }
        if (carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        
        return head;
    }
};