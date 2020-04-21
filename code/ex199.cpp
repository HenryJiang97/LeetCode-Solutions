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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)    return {};
        
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        res.push_back(root->val);
        
        while (!que.empty()) {
            int size = que.size();
            TreeNode* rightMost = NULL;
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                if (out->left != NULL) {
                    que.push(out->left);
                    rightMost = out->left;
                }
                if (out->right != NULL) {
                    que.push(out->right);
                    rightMost = out->right;
                }
            }
            if (rightMost != NULL)
                res.push_back(rightMost->val);
        }
        
        return res;
    }
};