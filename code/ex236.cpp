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
        int ret = helper(root, p, q);
        return res;
    }
    
private:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q) {    // Bitmask{p, q}, p => 10, q => 01, both => 11    // Get the existence of p and q of current subtree
        if (root == NULL)    return 0;
        
        int ret = 0;
        if (root == p)    ret |= (1 << 1);
        if (root == q)    ret |= (1 << 0);
        
        int left = helper(root->left, p, q);
        if (res != NULL)    return 3;
        int right = helper(root->right, p, q);
        if (res != NULL)    return 3;
        
        ret = ret | left | right;
        if (ret == 3)    res = root;
        
        return ret;
    }
};