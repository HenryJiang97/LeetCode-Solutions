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
    int minDepth(TreeNode* root) {
        if (root == NULL)    return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                if (out->left == NULL && out->right == NULL)    return depth + 1;
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
            depth++;
        }
        return -1;
    }
};