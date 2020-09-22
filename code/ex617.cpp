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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
    
private:
    TreeNode* merge(TreeNode* p1, TreeNode* p2) {
        if (p1 == NULL && p2 == NULL)    return NULL;
        int v1 = p1 == NULL ? 0 : p1->val;
        int v2 = p2 == NULL ? 0 : p2->val;
        TreeNode* p = new TreeNode(v1 + v2);
        p->left = merge(p1 == NULL ? NULL : p1->left, p2 == NULL ? NULL : p2->left);
        p->right = merge(p1 == NULL ? NULL : p1->right, p2 == NULL ? NULL : p2->right);
        return p;
    }
};