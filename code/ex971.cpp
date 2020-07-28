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
    vector<int> res;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (root->val != voyage[0])    return {-1};
        bool ret = dfs(root, voyage);
        return ret ? res : vector<int>{-1};
    }
    
private:
    bool dfs(TreeNode* root, vector<int>& voyage) {
        if (root == NULL)    return 1;
        if (root->val != voyage[i++])    return 0;
        
        if (root->left != NULL && root->left->val != voyage[i]) {    // Swap children
            // Swap left and right
            res.push_back(root->val);
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        } else {    // Not swap
            return dfs(root->left, voyage) && dfs(root->right, voyage);
        }
    }
};