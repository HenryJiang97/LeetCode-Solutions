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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX, last = INT_MIN / 2;
        traverse(root, diff, last);
        return diff;
    }
    
private:
    void traverse(TreeNode* root, int& diff, int& last) {
        if (root == NULL)    return;
        
        traverse(root->left, diff, last);
        
        diff = min(diff, root->val - last);
        last = root->val;
        
        traverse(root->right, diff, last);
    }
};