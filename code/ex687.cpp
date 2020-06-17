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
    int MAX = 0;
    
public:
    int longestUnivaluePath(TreeNode* root) {
        int ret = backtracking(root);
        return MAX;
    }
    
private:
    int backtracking(TreeNode* root) {
        if (root == NULL)    return 0;
        
        int val = root->val;
        int left = backtracking(root->left);
        int right = backtracking(root->right);
        
        if (root->left != NULL && root->left->val == val)    left++;
        else    left = 0;
        
        if (root->right != NULL && root->right->val == val)    right++;
        else    right = 0;
        
        MAX = max(MAX, left + right);
        return max(left, right);
    }
};