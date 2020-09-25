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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, p);
    }
    
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ilo, int ihi, int& p) {
        if (ilo > ihi)    return NULL;
        TreeNode* root = new TreeNode(postorder[p--]);
        int pivot = ilo;
        while (inorder[pivot] != root->val)    pivot++;
        root->right = build(inorder, postorder, pivot + 1, ihi, p);
        root->left = build(inorder, postorder, ilo, pivot - 1, p);
        return root;
    }
};