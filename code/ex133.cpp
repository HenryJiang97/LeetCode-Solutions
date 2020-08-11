/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> memo;
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)    return NULL;
        if (memo.count(node->val) > 0)    return memo[node->val];
        Node* nNode = new Node();
        nNode->val = node->val;
        memo[nNode->val] = nNode;
        for (Node* nei : node->neighbors) {
            (nNode->neighbors).push_back(cloneGraph(nei));
        }
        return nNode;
    }
};