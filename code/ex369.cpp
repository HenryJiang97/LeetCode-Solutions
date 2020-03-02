/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int carry = 1;
public:
    ListNode* plusOne(ListNode* head) {
        if (head == NULL)    return NULL;
        ListNode* nxt = helper(head);
        if (carry == 0)    return nxt;
        else {
            ListNode* curr = new ListNode(carry);
            curr->next = nxt;
            return curr;
        }
    }
    
private:
    ListNode* helper(ListNode* head) {
        if (head == NULL)    return NULL;
        ListNode* nxt = helper(head->next);
        int c = carry, val = 0;
        carry = (head->val + c) / 10;
        val = (head->val + c) % 10;
        ListNode* curr = new ListNode(val);
        curr->next = nxt;
        return curr;
    }
};