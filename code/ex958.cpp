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
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL)    return 1;
        queue<TreeNode*> que;
        que.push(root);
        bool meetNullBefore = 0;    // Save last meetNull state
        while (!que.empty()) {
            bool meetNull = 0;
            int size = que.size();
            for (int z = size; z > 0; z--) {
                auto out = que.front();    que.pop();
                if (out->left != NULL) {
                    if (meetNull)    return 0;
                    que.push(out->left);
                } else
                    meetNull = 1;
                if (out->right != NULL) {
                    if (meetNull)    return 0;
                    que.push(out->right);
                } else 
                    meetNull = 1;
            }
            if (!que.empty() && meetNullBefore)    return 0;
            meetNullBefore = meetNull;
        }
        return 1;
    }
};