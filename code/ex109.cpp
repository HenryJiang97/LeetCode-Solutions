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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> list;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        while (head != NULL) {
            list.push_back(head->val);
            head = head->next;
        }
        return build(0, list.size() - 1);
    }
    
private:
    TreeNode* build(int lo, int hi) {
        if (lo > hi)    return NULL;
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left = build(lo, mid - 1);
        root->right = build(mid + 1, hi);
        return root;
    }
};