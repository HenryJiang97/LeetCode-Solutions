/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (1) {
            if (cur == p)    break;
            else if (cur->val > p->val) {
                stk.push(cur);
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        
        if (cur->right == NULL && stk.empty())    return NULL;
        if (cur->right == NULL)    return stk.top();
        cur = cur->right;
        while (cur->left != NULL)    cur = cur->left;
        return cur;
    }
};