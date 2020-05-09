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
    bool isCousins(TreeNode* root, int x, int y) {
        int parent[101] = {0};
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            unordered_set<int> visited;
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                if (out->left != NULL) {
                    visited.insert(out->left->val);
                    parent[out->left->val] = out->val;
                    que.push(out->left);
                }
                if (out->right != NULL) {
                    visited.insert(out->right->val);
                    parent[out->right->val] = out->val;
                    que.push(out->right);
                }
            }
            if (visited.find(x) != visited.end() && visited.find(y) != visited.end() && parent[x] != parent[y])
                return 1;
        }
        
        return 0;
    }
};