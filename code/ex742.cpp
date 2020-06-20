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
    int findClosestLeaf(TreeNode* root, int k) { 
        // Convert tree to graph
        unordered_map<int, vector<int>> graph;
        unordered_set<int> leaves;
        getGraph(root, graph, leaves);
        
        // BFS to find the closest leaf
        queue<int> que;
        que.push(k);
        unordered_set<int> visited;
        visited.insert(k);
        
        while (!que.empty()) {
            int out = que.front();    que.pop();
            if (leaves.find(out) != leaves.end())    return out;
            if (graph.count(out) == 0)    continue;
            for (int nxt : graph[out]) {
                if (visited.find(nxt) != visited.end())    continue;
                visited.insert(nxt);
                que.push(nxt);
            }
        }
        
        return 0;
    }
    
private:
    void getGraph(TreeNode* root, unordered_map<int, vector<int>>& graph, unordered_set<int>& leaves) {
        if (root->left == NULL && root->right == NULL)    leaves.insert(root->val);
        if (root->left != NULL) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            getGraph(root->left, graph, leaves);
        }
        if (root->right != NULL) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            getGraph(root->right, graph, leaves);
        }
    }
};