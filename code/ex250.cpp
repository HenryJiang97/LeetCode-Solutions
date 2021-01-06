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
    int cnt = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ret = traverse(root);
        return cnt;
    }
    
private:
    int traverse(TreeNode* root) {
        if (root == NULL)    return INT_MIN;
        int left = traverse(root->left);
        int right = traverse(root->right);
        if (root->left != NULL && left != root->val)    return INT_MIN;
        if (root->right != NULL && right != root->val)    return INT_MIN;
        cnt++;
        return root->val;
    }
};