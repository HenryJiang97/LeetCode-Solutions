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
        string s = "";
        dfs1(root, s);
        return s;
    }
    
    void dfs1(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + " ";
        dfs1(root->left, s);
        dfs1(root->right, s);
    }

    // Decodes your encoded data to tree.
    int i = 0;
    
    TreeNode* deserialize(string data) {
        return dfs2(data);
    }
    
    TreeNode* dfs2(string data) {
        string cur = getNext(data);
        if (cur == "#")    return NULL;
        TreeNode* root = new TreeNode(stoi(cur));
        root->left = dfs2(data);
        root->right = dfs2(data);
        return root;
    }
    
    string getNext(string s) {
        string res = "";
        while (s[i] != ' ') {
            res += s[i++];
        }
        i++;
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;