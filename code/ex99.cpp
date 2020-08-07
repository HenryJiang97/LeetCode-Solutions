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
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        // Traverse for two nodes to be swapped
        traverse(root);
        
        // Swap
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
private:
    void traverse(TreeNode* root) {
        if (root == NULL)    return;
        
        traverse(root->left);
        if (first == NULL && root->val < prev->val)    first = prev;
        if (first != NULL && root->val < prev->val)    second = root;
        prev = root;
        traverse(root->right);
    }
};