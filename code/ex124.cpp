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
    int MAX = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        int ret = helper(root);
        return MAX;
    }

private:
    int helper(TreeNode* root) {
        if (root == NULL)    return 0;
        
        int val = root->val;
        int left = helper(root->left);
        left = left >= 0 ? left : 0;
        int right = helper(root->right);
        right = right >= 0 ? right : 0;
        
        MAX = max(MAX, val + left + right);
        return max(left, right) + val;
    }
};