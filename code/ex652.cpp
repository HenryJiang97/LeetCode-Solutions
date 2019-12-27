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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> cnt;
        string ret = dfs(root, cnt, res);
        return res;
    }
    
private:
    string dfs(TreeNode* root, unordered_map<string, int>& cnt, vector<TreeNode*>& res) {
        if (root == NULL)    return "#";
        
        string s = "";
        s += to_string(root->val);
        s += dfs(root->left, cnt, res);
        s += dfs(root->right, cnt, res);
        
        if (cnt.find(s) != cnt.end() && cnt[s] == 1)    res.push_back(root);
        cnt[s]++;
        return s;
    }
};