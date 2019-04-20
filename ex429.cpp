/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL)    return {};
              
        queue<Node*> que;
        que.push(root);
        
        vector<vector<int>> res;
        vector<int> first;
        first.push_back(root->val);
        res.push_back(first);
        
        
        vector<int> r;
        vector<Node*> newq;
        
        while (!que.empty()) {
            Node* out = que.front();    que.pop();
            
            for (Node* next : out->children) {
                r.push_back(next->val);
                newq.push_back(next);
            }
            
            if (que.empty() && newq.empty())    break;
            else if (que.empty()) {
                // Add the current layer to res
                res.push_back(r);
                r.clear();
                
                // Copy newq to que
                for (Node* n : newq)    que.push(n);
                newq.clear();
            }
        }

        return res;
    }
};