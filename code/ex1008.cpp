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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
    
private:
    TreeNode* helper(vector<int>& nodes, int lo, int hi) {
        if (lo > hi)    return NULL;
        
        int r = nodes[lo];
        TreeNode* root = new TreeNode(r);
        
        // Get split point
        int i = lo;
        while (i <= hi) {
            if (i == hi || nodes[i + 1] > r) {
                root->left = helper(nodes, lo + 1, i);
                root->right = helper(nodes, i + 1, hi);
                break;
            }
            i++;
        }
        
        return root;
    }
};