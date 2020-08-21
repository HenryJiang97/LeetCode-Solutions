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
    int MAX = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        int ret = backtracking(root);
        return MAX;
    }
    
private:
    int backtracking(TreeNode* root) {
        if (root == NULL)    return 0;
        int left = backtracking(root->left);
        int right = backtracking(root->right);
        int sum = left + right + root->val;
        MAX = max(MAX, sum);
        return max(max(root->val + left, root->val + right), 0);
    }
};