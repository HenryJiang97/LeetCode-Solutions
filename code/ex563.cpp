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
public:
    int findTilt(TreeNode* root) {
        return helper(root)[1];
    }
    
private:
    vector<int> helper(TreeNode* root) {    // {sum, tilt_sum}
        if (root == nullptr)    return {0, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        return {left[0] + right[0] + root->val, abs(left[0] - right[0]) + left[1] + right[1]};
    }
};