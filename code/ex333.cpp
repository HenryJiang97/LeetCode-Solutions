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
    int MAX = 0;
public:
    int largestBSTSubtree(TreeNode* root) {
        MAX = max(MAX, helper(root)[2]);
        return MAX;
    }
    
private:
    vector<int> helper(TreeNode* root) {    // {min_val, max_val, cnt}
        if (root == NULL)    return {INT_MAX, INT_MIN, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        // Not a BST
        if (left[2] == -1 || right[2] == -1)    return {0, 0, -1};
        if (left[2] != 0 && left[1] >= root->val || right[2] != 0 && right[0] <= root->val)
            return {0, 0, -1};
        
        // Is a BST
        MAX = max(MAX, left[2] + right[2] + 1);
        return {min(left[0], root->val), max(right[1], root->val), left[2] + right[2] + 1};
    }
};