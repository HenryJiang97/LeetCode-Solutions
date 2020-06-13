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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)    return -1;
        long secondMIN = min(helper(root->left, root->val), helper(root->right, root->val));
        return secondMIN == LONG_MAX ? -1 : (int)secondMIN;
    }
    
private:
    long helper(TreeNode* root, int MIN) {
        if (root == NULL)    return LONG_MAX;
        if (root->val != MIN)    return root->val;
        return min(helper(root->left, MIN), helper(root->right, MIN));
    }
};