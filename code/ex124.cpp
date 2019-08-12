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
        int sum = recurrsion(root);
        return MAX;
    }
    
private:
    int recurrsion(TreeNode* root) {    // Get the max path sum of current subtree
        if (root == NULL)    return INT_MIN;
        
        int left = recurrsion(root->left);
        int right = recurrsion(root->right);
        int m = max(left, right);
        
        MAX = max(MAX, root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0));    // Calculate the max sum path for this subtree 
        return root->val + (m > 0 ? m : 0);    // Return the max sum path passes current root node
    }
};