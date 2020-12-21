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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)    return res;
        
        queue<TreeNode*> que;
        que.push(root);
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            vector<int> layer;
            while (size--) {
                TreeNode* out = que.front();    que.pop();
                layer.push_back(out->val);
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
            if (step % 2 == 1)    reverse(layer.begin(), layer.end());
            res.push_back(layer);
            step++;
        }
        
        return res;
    }
};