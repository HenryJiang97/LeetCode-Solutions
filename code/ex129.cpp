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
    int sumNumbers(TreeNode* root) {
        if (root == NULL)    return 0;
        dfs(root, 0);
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += num;
            return;
        }
        if (root->left != NULL)    dfs(root->left, num);
        if (root->right != NULL)    dfs(root->right, num);
    }
};