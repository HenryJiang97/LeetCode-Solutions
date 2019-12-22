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
    int closestValue(TreeNode* root, double target) {
        double MIN = DBL_MAX;
        int res = root->val;
        TreeNode* p = root;
        while (p != NULL) {
            if (abs((double)(p->val) - target) < MIN) {
                res = p->val;
                MIN = abs((double)(p->val) - target);
            }
            if (MIN == 0.0)    break;
            p = (double)p->val > target ? p->left : p->right;
        }
        
        return res;
    }
};