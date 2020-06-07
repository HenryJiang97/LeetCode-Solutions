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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)    return {};
        
        vector<int> res;
        stack<TreeNode*> stk;
        addNodes(stk, root, res);
        
        while (!stk.empty()) {
            TreeNode* out = stk.top();    stk.pop();
            addNodes(stk, out->right, res);
        }
        
        return res;
    }
    
private:
    void addNodes(stack<TreeNode*>& stk, TreeNode* root, vector<int>& res) {
        while (root != NULL) {
            res.push_back(root->val);
            stk.push(root);
            root = root->left;
        }
    }
};