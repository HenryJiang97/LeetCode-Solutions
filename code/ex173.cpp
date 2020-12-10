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
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        addLeft(root);
    }
    
    int next() {
        TreeNode* out = stk.top();    stk.pop();
        if (out->right != NULL)    addLeft(out->right);
        return out->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
private:
    void addLeft(TreeNode* root) {
        for (TreeNode* p = root; p != NULL; p = p->left)    stk.push(p);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */