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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int lo1, int hi1, int lo2, int hi2) {
        if (lo1 > hi1)    return NULL;
        
        TreeNode* root = new TreeNode(postorder[hi2]);
        int pivot = -1;
        for (int i = lo1; i <= hi1; i++) {
            if (inorder[i] == postorder[hi2])
                pivot = i;
        }
        root->left = build(inorder, postorder, lo1, pivot - 1, lo2, hi2 - 1 - (hi1 - pivot));
        root->right = build(inorder, postorder, pivot + 1, hi1, lo2 - (hi1 - pivot), hi2 - 1);
        return root;
    }
};