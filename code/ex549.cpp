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
    int MAX = 1;
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)    return 0;
        auto ret = helper(root);
        return MAX;
    }
    
private:
    vector<int> helper(TreeNode* root) {
        if (root == NULL)    return {0, 0};
        
        int val = root->val;
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int lu = left[0], ld = left[1], ru = right[0], rd = right[1];
        if (root->left != NULL) {
            if (val == root->left->val + 1)    lu++;
            else    lu = 1;
            if (val == root->left->val - 1)    ld++;
            else    ld = 1;
        } else {
            lu = 1;
            ld = 1;
        }
        
        if (root->right != NULL) {
            if (val == root->right->val + 1)    ru++;
            else    ru = 1;
            if (val == root->right->val - 1)    rd++;
            else    rd = 1;
        } else {
            ru = 1;
            rd = 1;
        }
        
        MAX = max(MAX, max(max(lu, ld), max(ru, rd)));    // Parent-Children
        MAX = max(MAX, max(lu + rd - 1, ld + ru - 1));    // Children-Parent-Children
        
        return {max(lu, ru), max(ld, rd)};
    }
};