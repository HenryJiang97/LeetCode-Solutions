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
        if (head == NULL)    return NULL;

        // Slow and fast pointer to find the point where fast catch up slow
        ListNode* slow = head;
        ListNode* fast = head;
        int step = 0;
        while (1) {
            slow = slow->next;
            if (slow == NULL)    return NULL;
            fast = fast->next;
            if (fast == NULL)    return NULL;
            fast = fast->next;
            if (fast == NULL)    return NULL;
            step++;
            if (slow == fast)    break;
        }

        // Find the entry of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};