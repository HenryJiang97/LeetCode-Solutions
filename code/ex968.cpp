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
    int minCameraCover(TreeNode* root) {
        int ret = dfs(root);
        return ret == 0 ? cnt + 1 : cnt;
    }
    
private:
    // Not covered && no camera => 0
    // With camera => 1
    // No camera && covered => 2
    int dfs(TreeNode* root) {
        if (root == NULL)    return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {cnt++;    return 1;}
        if (left != 1 && right != 1)    return 0;
        return 2;
    }
};