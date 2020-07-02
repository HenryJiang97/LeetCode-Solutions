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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)    return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            vector<int> level;
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                level.push_back(out->val);
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
            res.push_back(level);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};