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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)    return {};
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, sum, res, cur);
        return res;
    }
    
private:
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& cur) {
        if (root->left == NULL && root->right == NULL) {
            if (sum - root->val == 0) {
                cur.push_back(root->val);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        
        cur.push_back(root->val);
        if (root->left != NULL)    dfs(root->left, sum - root->val, res, cur);
        if (root->right != NULL)    dfs(root->right, sum - root->val, res, cur);
        cur.pop_back();
    }
};