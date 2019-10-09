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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // Define the parent map to store the parent node of each node
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = root;
        
        // DFS search to find the last layer
        queue<TreeNode*> que;
        que.push(root);
        vector<TreeNode*> lastLayer;
        while (!que.empty())
        {
            lastLayer.clear();
            for (int z = que.size(); z > 0; --z)
            {
                auto out = que.front();    que.pop();
                lastLayer.push_back(out);
                
                if (out->left != NULL)
                {
                    que.push(out->left);
                    parent[out->left] = out;
                }
                if (out->right != NULL) 
                {
                    que.push(out->right);
                    parent[out->right] = out;
                }
            }
        }
        
        // Find common ancestor
        unordered_set<TreeNode*> s;
        for (auto node : lastLayer)    s.insert(node);
        while (1) {
            unordered_set<TreeNode*> temp;
            for (auto node : s) {
                temp.insert(parent[node]);
            }
            if (s.size() == 1)    break;
            s.clear();    s = temp;
        }
        
        return *(s.begin());
    }
};