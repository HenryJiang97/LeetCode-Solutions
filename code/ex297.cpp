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
    string serial = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        helper1(root);
        return serial;
    }
    
    // DFS helper to get the serial
    void helper1(TreeNode* root) {
        if (root == NULL) {
            serial = serial + "#,";
            return;
        }
        serial += to_string(root->val) + ",";
        helper1(root->left);
        helper1(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return helper2(data, idx);
    }
    
    // DFS helper to build the tree
    TreeNode* helper2(string& data, int& idx) {
        string next = getNext(data, idx);
        if (next == "")    return NULL;
        if (next == "#")    return NULL;
        else {
            TreeNode* root = new TreeNode(stoi(next));
            root->left = helper2(data, idx);
            root->right = helper2(data, idx);
            return root;
        }
    }
    
    string getNext(string& data, int& idx) {
        if (idx >= data.length())    return "";
        string s = "";
        while (data[idx] != ',') {
            s += data[idx++];
        }
        idx++;
        return s;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));