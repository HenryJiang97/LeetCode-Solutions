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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)    return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* out = que.front();    que.pop();
                if (size == 0)    res.push_back(out->val);
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
        }
        return res;
    }
};