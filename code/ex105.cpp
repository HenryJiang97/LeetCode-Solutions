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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& pre, vector<int>& in, int plo, int phi, int ilo, int ihi) {
        if (ilo > ihi)    return NULL;
        
        TreeNode* root = new TreeNode(pre[plo++]);
        
        // Find the pivot to split inorder array to left and right subtrees
        int pivot = 0;
        while (in[pivot] != root->val)    pivot++;
        
        // Build subtrees
        int nleft = pivot - ilo, nright = ihi - pivot - 1;
        root->left = build(pre, in, plo, plo + nleft - 1, ilo, pivot - 1);
        root->right = build(pre, in, plo + nleft, phi, pivot + 1, ihi);
        
        return root;
    }
};