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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)    return 0;
        return helper(root, sum, 0);
    }
    
private:
    bool helper(TreeNode* root, int sum, int cur) {
        if (root->left == NULL && root->right == NULL)    return sum == cur + root->val;
        bool left = root->left == NULL ? 0 : helper(root->left, sum, cur + root->val);
        bool right = root->right == NULL ? 0 : helper(root->right, sum, cur + root->val);
        return left || right;
    }
};