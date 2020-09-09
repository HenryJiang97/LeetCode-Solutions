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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* p = root;
        while (p != NULL) {
            nodes.push_back(p);
            p = p->next;
        }
        nodes.push_back(nullptr);
        nodes[nodes.size() - n - 2]->next = nodes[nodes.size() - n];
        return root->next;
    }
};