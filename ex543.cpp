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
    int longest = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)    return 0;
        
        int left_depth = longest_path(root->left);
        int right_depth = longest_path(root->right);
        
        longest = max(longest, left_depth + right_depth);
        return longest;
    }
    
private:
    int longest_path(TreeNode* root) {
        if (root == NULL)    return 0;
        
        int left_depth = longest_path(root->left);
        int right_depth = longest_path(root->right);
        
        longest = max(longest, left_depth + right_depth);
        
        return max(left_depth, right_depth) + 1;
    }
};