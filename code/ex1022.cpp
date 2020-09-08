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
    int res = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    
private:
    void dfs(TreeNode* root, int cur) {
        if (root->left == NULL && root->right == NULL) {
            res += (cur << 1) + root->val;
        }
        
        if (root->left != NULL)
            dfs(root->left, (cur << 1) + root->val);
        if (root->right != NULL)
            dfs(root->right, (cur << 1) + root->val);
    }
};