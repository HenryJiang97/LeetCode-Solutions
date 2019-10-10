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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val1, val2;
        findLeaves(root1, val1);
        findLeaves(root2, val2);
        
        if (val1.size() != val2.size())    return false;
        for (int i = 0; i < val1.size(); i++) {
            if (val1[i] != val2[i])    return false;
        }
        
        return true;
    }
    
private:
    void findLeaves(TreeNode* root, vector<int>& v) {
        if (root == NULL)    return;
        
        findLeaves(root->left, v);
        
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
        }
        
        findLeaves(root->right, v);
    }
};