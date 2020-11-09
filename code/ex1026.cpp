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
class Solution {
    int res = INT_MIN;
public:
    int maxAncestorDiff(TreeNode* root) {
        auto ret = helper(root);
        return res;
    }
    
private:
    vector<int> helper(TreeNode* root) {    // {min, max}
        if (root == NULL)    return {INT_MAX, INT_MIN};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        if (left[0] != INT_MAX) {
            res = max(res, max(abs(root->val - left[0]), abs(root->val - left[1])));
        }
        if (right[0] != INT_MAX) {
            res = max(res, max(abs(root->val - right[0]), abs(root->val - right[1])));
        }
        return {min(root->val, min(left[0], right[0])), max(root->val, max(left[1], right[1]))};
    }
};