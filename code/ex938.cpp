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
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int low, int high) {
        if (root == NULL)    return;
        if (root->val >= low && root->val <= high)    sum += root->val;
        if (root->val > low)    dfs(root->left, low, high);
        if (root->val < high)    dfs(root->right, low, high);
    }
};