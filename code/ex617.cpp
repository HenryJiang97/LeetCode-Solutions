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
        if (t1 == NULL)    return t2;
        merge(t1, t2);
        return t1;
    }
    
private:
    void merge(TreeNode* t1, TreeNode* t2) {
        if (t2 == NULL)    return;
        
        t1->val = t1->val + t2->val;
        
        // Go to left child
        if (t1->left == NULL && t2->left != NULL) {
            auto newNode = new TreeNode(0);
            t1->left = newNode;
        }
        
        // Go the right child
        if (t1->right == NULL && t2->right != NULL) {
            auto newNode = new TreeNode(0);
            t1->right = newNode;
        }
        
        merge(t1->left, t2->left);
        merge(t1->right, t2->right);
    }
};