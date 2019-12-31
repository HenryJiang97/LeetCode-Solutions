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
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (memo.find(N) != memo.end())
            return memo[N];
        
        vector<TreeNode*> res;
        if (N == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        
        for (int left = 1; left <= N - 2; left++) {
            int right = N - 1 - left;
            vector<TreeNode*> le = allPossibleFBT(left);
            vector<TreeNode*> ri = allPossibleFBT(right);
            for (TreeNode* l : le) {
                for (TreeNode* r : ri) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        
        memo[N] = res;
        return res;
    }
};