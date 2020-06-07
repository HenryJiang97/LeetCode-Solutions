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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)    return {};
        
        vector<int> res;
        stack<TreeNode*> stk;
        addNodes(stk, root);
        
        while (!stk.empty()) {
            TreeNode* out = stk.top();    stk.pop();
            res.push_back(out->val);
            addNodes(stk, out->right);
        }
        
        return res;
    }
    
private:
    void addNodes(stack<TreeNode*>& stk, TreeNode* root) {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }
};