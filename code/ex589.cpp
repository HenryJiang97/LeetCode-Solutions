/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL)    return {};
        vector<int> res{root->val};
        stack<pair<Node*, int>> stk;
        stk.push({root, 0});
        
        while (!stk.empty()) {
            Node* node = stk.top().first;
            vector<Node*> children = node->children;
            int i = stk.top().second;
            stk.pop();
            
            if (i < children.size()) {
                res.push_back(children[i]->val);
                stk.push({node, i + 1});
                stk.push({children[i], 0});
                i++;
            }
        }
        
        return res;
    }
};