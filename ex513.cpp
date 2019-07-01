// BFS

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        
        int res = 0;
        while (!que.empty()) {
            queue<TreeNode*> temp;
            res = que.front()->val;
            
            while (!que.empty()) {
                TreeNode* out = que.front();    que.pop();
                if (out->left != NULL)    temp.push(out->left);
                if (out->right != NULL)    temp.push(out->right);
            }
            
            if (temp.empty())    return res;
            
            // Copy temp to queue
            while (!temp.empty()) {
                que.push(temp.front());
                temp.pop();
            }
        }
        
        return 0;
    }
};