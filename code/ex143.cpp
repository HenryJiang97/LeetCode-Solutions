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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        for (ListNode* p = head; p != NULL; p = p->next)
            nodes.push_back(p);
        
        int n = nodes.size();
        for (int i = 0, j = n - 1; i < (n - 1) / 2; i++, j--) {
            nodes[j]->next = nodes[i]->next;
            nodes[i]->next = nodes[j];
            nodes[j - 1]->next = NULL;
        }
    }
};