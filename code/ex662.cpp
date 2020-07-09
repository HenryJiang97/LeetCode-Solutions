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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)    return 0;
        
        unsigned long MAX = 0;
        queue<pair<TreeNode*, unsigned long>> que;    // {Node, idx}
        que.push({root, 1});
        
        while (!que.empty()) {
            int size = que.size();
            unsigned long lo = -1, hi = -1;
            for (int z = size; z > 0; z--) {
                auto out = que.front();    que.pop();
                if (z == size)    lo = out.second;
                if (z == 1)    hi = out.second;
                if (out.first->left != NULL)    que.push({out.first->left, out.second * 2});
                if (out.first->right != NULL)    que.push({out.first->right, out.second * 2 + 1});
            }
            MAX = max(MAX, hi - lo + 1);
        }
        
        return (int)MAX;
    }
};