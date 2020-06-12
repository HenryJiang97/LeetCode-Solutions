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
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* newRoot = root;
        while (newRoot != NULL && (newRoot->val > R || newRoot->val < L)) {
            if (newRoot->val > R)    newRoot = newRoot->left;
            else if (newRoot->val < L)    newRoot = newRoot->right;
        }
        if (newRoot == NULL)    return NULL;
        
        newRoot->left = trimBST(newRoot->left, L, R);
        newRoot->right = trimBST(newRoot->right, L, R);
        
        return newRoot;
    }
};