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
    int n;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        n = pre.size();
        return construct(pre, 0, n - 1, post, 0, n - 1);
    }
    
private:
    TreeNode* construct(vector<int>& pre, int preLo, int preHi, vector<int>& post, int postLo, int postHi) {
        if (preLo > preHi || postLo > postHi)    return NULL;
        
        TreeNode* root = new TreeNode(pre[preLo]);
        if (preLo == preHi)    return root;
        
        // Find the divide point for left and right children
        int leftRoot = pre[preLo + 1], rightRoot = post[postHi - 1];
        if (leftRoot == rightRoot) {
            root->left = construct(pre, preLo + 1, preHi, post, postLo, postHi - 1);
            return root;
        }
        
        int dividePre = preHi, dividePost = postLo;
        while (post[dividePost] != leftRoot)    dividePost++;
        while (pre[dividePre] != rightRoot)    dividePre--;
        root->left = construct(pre, preLo + 1, dividePre - 1, post, postLo, dividePost);
        root->right = construct(pre, dividePre, preHi, post, dividePost + 1, postHi - 1);
        return root;
    }
};