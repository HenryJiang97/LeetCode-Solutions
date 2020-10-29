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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == NULL)    return NULL;
        TreeNode* newRoot = new TreeNode(root->val);
        queue<pair<TreeNode*, Node*>> que;
        que.push({newRoot, root});
        while (!que.empty()) {
            auto out = que.front();    que.pop();
            TreeNode* tn = out.first;    Node* n = out.second;
            TreeNode* head = NULL;
            TreeNode* p = NULL;
            for (Node* nxt : n->children) {
                TreeNode* cur = new TreeNode(nxt->val);
                if (head == NULL)    head = p = cur;
                else    {p->right = cur;    p = p->right;}
                que.push({cur, nxt});
            }
            tn->left = head;
        }
        return newRoot;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        return buildTree(root);
    }
    
    Node* buildTree(TreeNode* cur) {
        if (cur == NULL)    return NULL;
        
        Node* root = new Node(cur->val);
        TreeNode* p = cur->left;
        vector<Node*> children;
        while (p != NULL) {
            children.push_back(buildTree(p));
            p = p->right;
        }
        root->children = children;
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));