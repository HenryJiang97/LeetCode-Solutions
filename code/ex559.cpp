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
    int maxDepth(Node* root) {
        if (root == NULL)    return 0;
        
        int depth = 0;
        
        queue<Node*> queue;
        queue.push(root);
        
        vector<Node*> temp;
        while (!queue.empty()) {
            Node* out = queue.front();    queue.pop();
            
            for (auto child : out->children)
                temp.push_back(child);
            
            // Add nodes in temp to the queue
            if (queue.empty()) {
                for (auto t : temp)    queue.push(t);
                depth++;
                temp.clear();
            }
        }
        
        return depth;
    }
};