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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));
        for (int i = 1; i <= n; i++)    dp[i][i].push_back(new TreeNode(i));
        
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n + 1 - l; i++) {
                int j = i + l - 1;
                
                for (int mid = i; mid <= j; mid++) {
                    vector<TreeNode*> leftNodes = dp[i][mid - 1];
                    vector<TreeNode*> rightNodes = dp[mid + 1][j];

                    if (leftNodes.size() == 0) {
                        for (TreeNode* right : rightNodes) {
                            dp[i][j].push_back(generateNode(mid, NULL, right));
                        }
                    }

                    else if (rightNodes.size() == 0) {
                        for (TreeNode* left : leftNodes) {
                            dp[i][j].push_back(generateNode(mid, left, NULL));
                        }
                    }

                    else {
                        for (TreeNode* left : leftNodes) {
                            for (TreeNode* right : rightNodes) {
                                dp[i][j].push_back(generateNode(mid, left, right));
                            }
                        }
                    }
                }
            }
        }
        
        return dp[1][n];
    }
    
private:
    TreeNode* generateNode(int rootVal, TreeNode* left, TreeNode* right) {
        TreeNode* root = new TreeNode(rootVal);
        root->left = left;
        root->right = right;
        return root;
    }
};