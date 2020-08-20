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
    string MIN = "";
public:
    string smallestFromLeaf(TreeNode* root) {
        MIN += (char)('z' + 1);
        dfs(root, "");
        return MIN;
    }
    
private:
    void dfs(TreeNode* root, string cur) {
        if (root->left == NULL && root->right == NULL) {
            MIN = min(MIN, (char)(root->val + 'a') + cur);
            return;
        }
        if (root->left != NULL)    dfs(root->left, (char)(root->val + 'a') + cur);
        if (root->right != NULL)    dfs(root->right, (char)(root->val + 'a') + cur);
    }
};