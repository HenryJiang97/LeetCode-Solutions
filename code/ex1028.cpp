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
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int, int>> val2dep = getVal2Dep(S);
        int idx = 0;
        return helper(val2dep, idx, 0);
    }
    
private:
    TreeNode* helper(vector<pair<int, int>>& val2dep, int& idx, int depth) {
        if (idx >= val2dep.size())    return NULL;
        int val = val2dep[idx].first, num = val2dep[idx].second;
        if (num < depth)    return NULL;
        
        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = helper(val2dep, idx, depth + 1);
        root->right = helper(val2dep, idx, depth + 1);
        return root;
    }
    
    vector<pair<int, int>> getVal2Dep(string s) {
        s += '-';
        vector<pair<int, int>> val2dep;
        int cnt = 0, num = 0;
        for (char c : s) {
            if (c == '-') {
                if (num == 0)    cnt++;
                else {
                    val2dep.push_back({num, cnt});
                    cnt = 1;
                    num = 0;
                }
            } else {
                num = num * 10 + (c - '0');
            }
        }
        return val2dep;
    }
};