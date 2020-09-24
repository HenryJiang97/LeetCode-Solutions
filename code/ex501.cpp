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
    int MAX = 0;
    int prev = INT_MIN, cnt = 0;
    vector<int> modes;
public:
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)    return {};
        inorder(root);
        if (cnt >= MAX) {    // Update modes array
            if (cnt > MAX)    modes.clear();
            modes.push_back(prev);
        }
        return modes;
    }
    
private:
    void inorder(TreeNode* root) {
        if (root == NULL)    return;
        inorder(root->left);
        if (root->val == prev) {
            cnt++;
        } else {
            if (cnt >= MAX) {    // Update modes array
                if (cnt > MAX)    modes.clear();
                MAX = cnt;
                modes.push_back(prev);
            }
            prev = root->val;
            cnt = 1;
        }
        inorder(root->right);
    }
};