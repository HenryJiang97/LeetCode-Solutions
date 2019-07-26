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
    bool exist = false;
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        traverse(s, t);
        
        return exist;
    }
    
private:
    void traverse(TreeNode* s, TreeNode* t) {
        if (s == NULL)    return;
        
        bool res = false;
        if (s->val == t->val)    res = check(s, t);
        if (res)    {exist = true;    return;}
        
        // Pre-order traverse
        traverse(s->left, t);
        if (exist)    return;
        
        traverse(s->right, t);
        if (exist)    return;
    }
    
    bool check(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL)    return true;
        if ((s == NULL) || (t == NULL))    return false;
        
        // Pre-order traverse
        bool res = true;
        if (s->val != t->val)    return false;
        
        res = check(s->left, t->left);
        if (!res)    return false;
        
        res = check(s->right, t->right);
        if (!res)    return false;
        
        return res;
    }
};