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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)    return {};
        
        stack<TreeNode*> stk;
        stack<int> vals;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* out = stk.top();    stk.pop();
            vals.push(out->val);
            
            if (out->left != NULL)    stk.push(out->left);
            if (out->right != NULL)    stk.push(out->right);
        }
        
        // Get traversal
        vector<int> res;
        while (!vals.empty()) {
            res.push_back(vals.top());
            vals.pop();
        }
        
        return res;
    }
};