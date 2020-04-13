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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Add digits to stacks
        stack<int> s1, s2;
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        // Get sum
        ListNode* head = NULL;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int n1 = s1.empty() ? 0 : s1.top();
            int n2 = s2.empty() ? 0 : s2.top();
            if (!s1.empty())    s1.pop();
            if (!s2.empty())    s2.pop();
            ListNode* newHead = new ListNode((n1 + n2 + carry) % 10);
            carry = (n1 + n2 + carry) / 10;
            newHead->next = head;
            head = newHead;
        }
        
        return head;
    }
};