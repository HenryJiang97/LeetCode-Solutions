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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        for (ListNode*p = head; p != NULL; p = p->next)    len++;
        
        stack<int> stk;
        ListNode* p = head;
        for (int i = 0; i < len / 2; i++) {
            stk.push(p->val);
            p = p->next;
        }
        if (len % 2 == 1)    p = p->next;
        
        for (int i = 0; i < len / 2; i++) {
            if (stk.top() != p->val)    return 0;
            stk.pop();    p = p->next;
        }
        return 1;
    }
};