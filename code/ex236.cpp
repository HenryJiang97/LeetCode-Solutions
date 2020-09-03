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
    TreeNode* res = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool ret = backtracking(root, p, q);
        return res;
    }
    
private:
    bool backtracking(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)    return 0;
        bool left = backtracking(root->left, p, q);
        bool right = backtracking(root->right, p, q);
        if (res == NULL && ((left && right) || (root == p || root == q) && (left || right)))    res = root;
        return left || right || root == p || root == q;
    }
};