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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL)    return {};
        
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            queue<TreeNode*> temp;
            int MAX = INT_MIN;
            
            while (!que.empty()) {
                TreeNode* out = que.front();    que.pop();
                MAX = max(MAX, out->val);
                if (out->left != NULL)    temp.push(out->left);
                if (out->right != NULL)    temp.push(out->right);
            }
            
            // Push max to result
            res.push_back(MAX);
            
            // Copy temp to queue
            while (!temp.empty()) {
                que.push(temp.front());
                temp.pop();
            }
        }
        
        return res;
    }
};