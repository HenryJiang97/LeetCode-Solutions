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
    int rob(TreeNode* root) {
        return max(dfs(root)[0], dfs(root)[1]);
    }
    
private:
    vector<int> dfs(TreeNode* root) {    // {rob_current, not_rob_current}
        if (root == NULL)    return {0, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        return {left[1] + right[1] + root->val, max(max(left[0] + right[0], left[1] + right[1]), max(left[0] + right[1], left[1] + right[0]))};
    }
};