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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        getGraph(graph, root);
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int dis = 0;
        vector<int> res;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                TreeNode* out = que.front();    que.pop();
                if (dis == K)    res.push_back(out->val);
                for (TreeNode* nxt : graph[out]) {
                    if (visited.count(nxt) > 0)    continue;
                    visited.insert(nxt);
                    que.push(nxt);
                }
            }
            if (++dis > K)    break;
        }
        
        return res;
    }
    
private:
    void getGraph(unordered_map<TreeNode*, vector<TreeNode*>>& graph, TreeNode* root) {
        if (root->left != NULL) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            getGraph(graph, root->left);
        }
        if (root->right != NULL) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            getGraph(graph, root->right);
        }
    }
};