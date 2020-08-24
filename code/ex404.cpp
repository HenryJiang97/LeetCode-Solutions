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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)    return sum;
        dfs(root, 1);
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int dir) {
        if (root->left == NULL && root->right == NULL) {    // Leaves
            if (dir == 0)    sum += root->val;
            return;
        }
        
        if (root->left != NULL)    dfs(root->left, 0);
        if (root->right != NULL)    dfs(root->right, 1);
    }
};