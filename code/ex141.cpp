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
    bool hasCycle(ListNode *head) {
        if (head == NULL)    return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while (1) {
            if (slow == NULL)    break;
            slow = slow->next;
            if (fast == NULL)    break;
            fast = fast->next;
            if (fast == NULL)    break;
            fast = fast->next;
            if (slow == fast)    return 1;
        }
        return 0;
    }
};