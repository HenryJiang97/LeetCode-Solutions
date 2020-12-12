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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> parent(501, NULL);
        
        queue<TreeNode*> que;
        que.push(root);
        parent[root->val] = root;
        vector<TreeNode*> leaves;
        while (!que.empty()) {
            int size = que.size();
            leaves = vector<TreeNode*>();
            while (size--) {
                TreeNode* out = que.front();    que.pop();
                leaves.push_back(out);
                if (out->left != NULL) {
                    parent[out->left->val] = out;
                    que.push(out->left);
                }
                if (out->right != NULL) {
                    parent[out->right->val] = out;
                    que.push(out->right);
                }
            }
        }
        
        // Find the cloest common ancestor
        while (1) {
            if (sameNode(leaves))    return leaves[0];
            for (int i = 0; i < leaves.size(); i++) {
                leaves[i] = parent[leaves[i]->val];
            }
        }
        
        return NULL;
    }
    
private:
    bool sameNode(vector<TreeNode*>& leaves) {
        int pivot = leaves[0]->val;
        for (TreeNode* l : leaves) {
            if (l->val != pivot)    return 0;
        }
        return 1;
    }
};