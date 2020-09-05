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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1 = getNodes(root1);
        vector<int> nodes2 = getNodes(root2);
        vector<int> res;
        int n1 = nodes1.size(), n2 = nodes2.size(), p1 = 0, p2 = 0;
        while (p1 < n1 || p2 < n2) {
            if (p1 >= n1)    res.push_back(nodes2[p2++]);
            else if (p2 >= n2)    res.push_back(nodes1[p1++]);
            else if (nodes1[p1] < nodes2[p2])    res.push_back(nodes1[p1++]);
            else    res.push_back(nodes2[p2++]);
        }
        return res;
    }
    
private:
    vector<int> getNodes(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == NULL)    return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};