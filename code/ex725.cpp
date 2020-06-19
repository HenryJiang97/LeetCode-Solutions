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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // Get the length of linked list
        int n = 0;
        ListNode* p = root;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        
        // Get the length for each part
        int len = n / k;
        int cnt = n - len * k;    // Parts which need length of len + 1
        
        // Split
        // Front part with length of len + 1
        vector<ListNode*> res;
        p = root;
        for (int i = 0; i < cnt; i++) {
            getPart(res, p, len);
        }
        
        // End part with length of len
        for (int i = 0; i < k - cnt; i++) {
            getPart(res, p, len - 1);
        }
        
        return res;
    }
    
private:
    void getPart(vector<ListNode*>& res, ListNode*& p, int len) {
            ListNode* head = p;
            if (p == NULL) {
                res.push_back(p);
                return;
            }
            
            for (int j = 0; j < len; j++) {
                p = p->next;
            }
            ListNode* end = p;
            p = p->next;
            end->next = NULL;
            res.push_back(head);
    }
};