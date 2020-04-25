/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(count(nodes) * logn)

struct cmp {
    bool operator()(ListNode* p1, ListNode* p2) {
        return p1->val > p2->val;
    }   
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < n; i++)    // O(nlogn)
            if (lists[i] != NULL)    pq.push(lists[i]);
        
        ListNode* head = new ListNode(0);
        head->next = NULL;
        ListNode* p = head;
        while (!pq.empty()) {    // O(count(nodes) * logn)
            ListNode* out = pq.top();    pq.pop();
            if (out->next != NULL)    pq.push(out->next);
            out->next = NULL;
            p->next = out;
            p = p->next;
        }
        
        return head->next;
    }
};