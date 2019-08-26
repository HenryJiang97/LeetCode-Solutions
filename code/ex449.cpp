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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream res;
        serializeHelper(root, res);
        return res.str();
    }
    
    void serializeHelper(TreeNode* root, ostringstream& s) {
        if (root == NULL)    s << "# ";
        else {
            s << to_string(root->val) << " ";
            serializeHelper(root->left, s);
            serializeHelper(root->right, s);
        }
    }

    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserializeHelper(is);
    }

    
    TreeNode* deserializeHelper(istringstream& is) {
        string s = "";
        is >> s;
        
        if (s == "#") {
            return NULL;
        } else {
            TreeNode* root = new TreeNode(stoi(s));
            root->left = deserializeHelper(is);
            root->right = deserializeHelper(is);
            return root;
        }
    } 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));