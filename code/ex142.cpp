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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (1) {
            if (slow == NULL)    return NULL;
            slow = slow->next;
            if (fast == NULL)    return NULL;
            fast = fast->next;
            if (fast == NULL)    return NULL;
            fast = fast->next;
            if (slow == fast)    break;
        }
        
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};