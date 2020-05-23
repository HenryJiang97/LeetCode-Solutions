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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> stk;    // {val, idx}
        vector<int> res;
        
        for (ListNode* p = head; p != NULL; p = p->next) {
            res.push_back(0);
            while (!stk.empty() && stk.top().first < p->val) {
                res[stk.top().second] = p->val;
                stk.pop();
            }
            
            stk.push(pair(p->val, res.size() - 1));
        }
        
        return res;
    }
};