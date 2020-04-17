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
    int p = 0;
public:
    TreeNode* str2tree(string s) {
        if (s == "")    return NULL;
        int num = 0, sign = 1;
        TreeNode* root = NULL;
        while (p < s.length()) {
            char c = s[p];
            if (c == '(') {
                p++;
                if (root == NULL)    root = new TreeNode(sign * num);
                TreeNode* next = str2tree(s);
                if (root->left == NULL)    root->left = next;
                else    root->right = next;
            } else if (c == ')') {
                p++;
                if (root == NULL)    return new TreeNode(sign * num);
                else return root;
            } else if (c == '-') {
                p++;
                sign = -1;
            } else {
                num = num * 10 + (int)(c - '0');
                p++;
            }
        }
        if (root == NULL)    return new TreeNode(sign * num);
        else return root;
    }
};