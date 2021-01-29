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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> traversal;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<TreeNode*, int> out = que.front();    que.pop();
                TreeNode* node = out.first;
                int col = out.second;
                traversal[col][level].insert(node->val);
                if (node->left != NULL)    que.push({node->left, col - 1});
                if (node->right != NULL)    que.push({node->right, col + 1});
            }
            level++;
        }
        
        vector<vector<int>> res;
        for (auto& [k, v] : traversal) {
            vector<int> col;
            for (auto& [kk, vv] : v) {
                for (int vvv : vv) {
                    col.push_back(vvv);
                }
            }
            res.push_back(col);
        }
        return res;
    }
};