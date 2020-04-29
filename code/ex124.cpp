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
    int MAX = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        int ret = dfs(root);
        return MAX;
    }
    
private:
    int dfs(TreeNode* root) {
        if (root == NULL)    return 0;
        
        int rootVal = root->val;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        MAX = max(MAX, rootVal);
        MAX = max(MAX, max(max(left + rootVal, right + rootVal), left + right + rootVal));
        
        return max(max(left + rootVal, right + rootVal), rootVal);
    }
};