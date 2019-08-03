// BFS

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL)    return {};
        
        // (Column - array of tree nodes on that column) map
        map<int, vector<TreeNode*>> m;
        
        // (TreeNode - it's column number) pair
        queue<pair<TreeNode*, int>> que;
        
        // Init queue
        m[0].push_back(root);
        pair<TreeNode*, int> r = make_pair(root, 0);
        que.push(r);
        
        
        while (!que.empty()) {
            pair<TreeNode*, int> out = que.front();    que.pop();
            
            if (out.first->left != NULL) {
                m[out.second - 1].push_back(out.first->left);
                que.push(make_pair(out.first->left, out.second - 1));
            }
            
            if (out.first->right != NULL) {
                m[out.second + 1].push_back(out.first->right);
                que.push(make_pair(out.first->right, out.second + 1));
            }
        }
        
        // Get the result
        auto res = vector<vector<int>>();
        
        for (auto entry : m) {
            vector<int> temp;
            for (TreeNode* nodes : entry.second) {
                temp.push_back(nodes->val);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};