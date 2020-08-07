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
    map<int, map<int, vector<int>>> map;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& [k, v] : map) {
            vector<int> col;
            for (auto& [k1, v1] : v) {
                sort(v1.begin(), v1.end());
                for (int val : v1) {
                    col.push_back(val);
                }
            }
            res.push_back(col);
        }
        return res;
    }
    
private:
    void dfs(TreeNode* root, int row, int col) {
        if (root == NULL)    return;
        map[col][row].push_back(root->val);
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
};