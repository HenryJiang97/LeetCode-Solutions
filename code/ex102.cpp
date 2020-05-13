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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)    return res;
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> layer;
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                layer.push_back(out->val);
                if (out->left != nullptr)    que.push(out->left);
                if (out->right != nullptr)    que.push(out->right);
            }
            res.push_back(layer);
        }
        
        return res;
    }
};