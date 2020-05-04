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
    bool res = 1;
    
public:
    bool isValidBST(TreeNode* root) {
        auto ret = dfs(root);
        return res;
    }
    
private:
    vector<long> dfs(TreeNode* root) {    // {min, max}
        if (root == NULL)    return {LONG_MAX, LONG_MIN};
        
        int val = root->val;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left[1] >= val || right[0] <= val) {
            res = 0;
            return {LONG_MAX, LONG_MIN};
        }
        
        return {min((long)val, left[0]), max((long)val, right[1])};
    }
};