/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef long long int64;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)    return 0;
        
        queue<TreeNode*> nodes;    nodes.push(root);
        queue<int64> idx;    idx.push(1);
        int64 MAX = 1;
        
        vector<TreeNode*> temp_nodes;
        vector<int64> temp_idx;
        while (!nodes.empty()) {
            TreeNode* out_node = nodes.front();    nodes.pop();
            int64 out_idx = idx.front();    idx.pop();
            
            if (out_node->left != NULL) {
                temp_nodes.push_back(out_node->left);
                temp_idx.push_back(out_idx * 2);
            }
            if (out_node->right != NULL) {
                temp_nodes.push_back(out_node->right);
                temp_idx.push_back(out_idx * 2 + 1);
            }
            
            if (nodes.empty()) {
                // Copy elements from temp vectors back to queue
                if (temp_nodes.size() != 0) {
                    MAX = max(MAX, temp_idx[temp_idx.size() - 1] - temp_idx[0] + 1);
                    
                    for (auto& tn : temp_nodes)    nodes.push(tn);
                    
                    if (temp_idx.size() == 1)    idx.push(1);
                    else    for (auto& ti : temp_idx)    idx.push(ti);
                    
                    temp_nodes.clear();    temp_idx.clear();
                }   
            }
        }
        
        return MAX;
    }
};