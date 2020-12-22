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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* prev = NULL;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* out = que.front();    que.pop();
                if (prev == u)    return out;
                if (out == u && size == 0)    return NULL;
                prev = out;
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
        }
        return NULL;
    }
};