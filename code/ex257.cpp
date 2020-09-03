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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)    return {};
        vector<string> res;
        dfs(root, res, "");
        return res;
    }
    
private:
    void dfs(TreeNode* root, vector<string>& res, string cur) {
        if (root->left == NULL && root->right == NULL) {
            cur += to_string(root->val);
            res.push_back(cur);
            return;
        }
        
        cur += to_string(root->val) + "->";
        if (root->left != NULL)    dfs(root->left, res, cur);
        if (root->right != NULL)    dfs(root->right, res, cur);
    }
};