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
    int res = 0;
    vector<int> cnt;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt.resize(10);
        dfs(root);
        return res;
    }
    
private:
    void dfs(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            cnt[root->val]++;
            if (valid())    res++;
            cnt[root->val]--;
            return;
        }
        cnt[root->val]++;
        if (root->left != NULL)    dfs(root->left);
        if (root->right != NULL)    dfs(root->right);
        cnt[root->val]--;
    }
    
    bool valid() {
        int odd = 0;
        for (int i = 1; i <= 9; i++) {
            odd += cnt[i] % 2;
        }
        return odd <= 1;
    }
};