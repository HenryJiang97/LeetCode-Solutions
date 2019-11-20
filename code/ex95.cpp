// DP

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
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)    return {};
        
        vector<vector<vector<TreeNode*>>> dp(n, vector<vector<TreeNode*>>(n));
        for (int i = 0; i < n; i++)    dp[i][i].push_back(new TreeNode(i + 1));
        
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                
                // Union
                for (TreeNode* r : dp[i + 1][j]) {
                    TreeNode* root = new TreeNode(i + 1);
                    root->right = r;
                    dp[i][j].push_back(root);
                }
                
                for (int k = i + 1; k <= j - 1; k++) {
                    for (TreeNode* l : dp[i][k - 1]) {
                        for (TreeNode* r : dp[k + 1][j]) {
                            TreeNode* root = new TreeNode(k + 1);
                            root->left = l;
                            root->right = r;
                            dp[i][j].push_back(root);
                        }
                    }
                }
                
                for (TreeNode* l : dp[i][j - 1]) {
                    TreeNode* root = new TreeNode(j + 1);
                    root->left = l;
                    dp[i][j].push_back(root);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};