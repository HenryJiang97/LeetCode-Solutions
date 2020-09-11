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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL)    return {};
        
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size(), cnt = 0;
            double sum = 0.0;
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                sum += out->val;    cnt++;
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
            res.push_back(sum / cnt);
        }
        
        return res;
    }
};