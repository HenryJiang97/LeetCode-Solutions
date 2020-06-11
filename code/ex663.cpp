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
    TreeNode* r;
    unordered_set<int> memo;
public:
    bool checkEqualTree(TreeNode* root) {
        this->r = root;
        int sum = getSum(root);
        if (sum % 2 != 0)    return 0;
        for (int m : memo)
            if (m == sum / 2)    return 1;
        return 0;
    }
    
private:
    int getSum(TreeNode* root) {
        if (root == NULL)    return 0;
        int sum = root->val + getSum(root->left) + getSum(root->right);
        if (root != r)    memo.insert(sum);
        return sum;
    }
};