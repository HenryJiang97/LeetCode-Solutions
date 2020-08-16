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
    bool res = 1;
public:
    bool isBalanced(TreeNode* root) {
        int ret = dfs(root);
        return res;
    }
    
private:
    int dfs(TreeNode* root) {
        if (root == NULL)    return 0;
        int left = dfs(root->left);
        if (!res)    return 0;
        int right = dfs(root->right);
        if (!res)    return 0;
        if (abs(left - right) > 1)    res = 0;
        return max(left, right) + 1;
    }
};