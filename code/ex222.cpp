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
    int countNodes(TreeNode* root) {
        if (root == NULL)    return 0;
        int h = getHeight(root);
        int totalNodes = pow(2, h) - 1;
        int vacant = 0;    bool end = 0;
        getVacant(root, h, 0, vacant, end);
        return totalNodes - vacant;
    }
    
private:
    int getHeight(TreeNode* root) {
        int height = 0;
        while (root != NULL) {
            root = root->left;
            height++;
        }
        return height;
    }
    
    void getVacant(TreeNode* root, int height, int h, int& vacant, bool& end) {
        if (h == height - 1) {
            if (root == NULL)    vacant++;
            else    end = 1;
            return;
        }
        getVacant(root->right, height, h + 1, vacant, end);
        if (end)    return;
        getVacant(root->left, height, h + 1, vacant, end);
    }
};