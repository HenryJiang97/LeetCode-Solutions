/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)    return NULL;
        if (map.count(head) > 0)    return map[head];

        Node* root = new Node(head->val);
        map[head] = root;
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);
        
        return root;
    }
};