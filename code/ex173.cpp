/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* node;
    stack<TreeNode*> stk;
    
    BSTIterator(TreeNode* root) {
        node = root;
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }        
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stk.top();    stk.pop();
        int ret = cur->val;
        
        if (cur->right != NULL) {
            stk.push(cur->right);
            cur = cur->right->left;
            while (cur != NULL) {
                stk.push(cur);
                cur = cur->left;
            }
        }       
        
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */