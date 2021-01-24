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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push({node->val, node});
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (!pq.empty()) {
            int val = pq.top().first;
            ListNode* node = pq.top().second;
            pq.pop();
            if (node->next != NULL)    pq.push({node->next->val, node->next});
            p->next = node;
            p = p->next;
            p->next = NULL;
        }
        
        return head->next;
    }
};