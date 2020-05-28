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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                
                if (depth == d - 2) {
                    TreeNode* nxt = out->left;
                    out->left = new TreeNode(v);
                    out->left->left = nxt;
                } 
                else if (out->left != NULL) {
                    que.push(out->left);
                }
                
                if (depth == d - 2) {
                    TreeNode* nxt = out->right;
                    out->right = new TreeNode(v);
                    out->right->right = nxt;
                } else if (out->right != NULL) {
                    que.push(out->right);
                }
            }
            if (depth == d - 2)    break;
            depth++;
        }
        
        return root;
    }
};