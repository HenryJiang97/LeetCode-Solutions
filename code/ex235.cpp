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
    TreeNode* ancestor = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return ancestor;
    }
    
private:
    int dfs(TreeNode* root, int p, int q) {
        if (root == NULL)    return 0;
        int left = dfs(root->left, p, q);
        if (ancestor != NULL)    return 0;
        int right = dfs(root->right, p, q);
        if (ancestor != NULL)    return 0;
        int cur = root->val == p ? 1 : root->val == q ? 2 : 0;
        if (left + cur == 3 || left + right == 3 || right + cur == 3) {
            ancestor = root;
        }
        if (cur == 1 || left == 1 || right == 1)    return 1;
        if (cur == 2 || left == 2 || right == 2)    return 2;
        return 0;
    }
};