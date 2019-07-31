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
    int maxDepth = 0;
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> map;
        
        // Get leaf nodes on each tree layer and the maxDepth
        preOrderTraverse(root, map);
        
        auto res = vector<vector<int>>(maxDepth, vector<int>());
        for (auto& entry : map) {
            res[entry.second - 1].push_back(entry.first->val);
        }
        
        return res;
    }
    
private:
    int preOrderTraverse(TreeNode* root, unordered_map<TreeNode*, int>& map) {
        if (root == NULL)    return 0;
        
        int left = preOrderTraverse(root->left, map);
        int right = preOrderTraverse(root->right, map);
        
        map[root] = max(left, right) + 1;
        maxDepth = max(maxDepth, map[root]);
        return map[root];
    }
};