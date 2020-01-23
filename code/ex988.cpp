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
    string MIN = "";
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return MIN;
    }
    
private:
    void dfs(TreeNode* root, string cur) {
        string newStr = (char)('a' + root->val) + cur;
        if (root->left == NULL && root->right == NULL) {    // Meet leaf
            if (MIN == "")    MIN = newStr;
            else    MIN = min(MIN, newStr);
            return;
        }
        else {
            if (root->left != NULL)
                dfs(root->left, newStr);
            if (root->right != NULL)
                dfs(root->right, newStr);
        }
    }
};