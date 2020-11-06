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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = root;
        
        queue<TreeNode*> que;
        que.push(root);
        vector<TreeNode*> last;
        while (!que.empty()) {
            int size = que.size();
            last.clear();
            while (size--) {
                TreeNode* out = que.front();    que.pop();
                last.push_back(out);
                if (out->left != NULL) {
                    parent[out->left] = out;
                    que.push(out->left);
                }
                if (out->right != NULL) {
                    parent[out->right] = out;
                    que.push(out->right);
                }
            }
        }
        
        // Find the closest common parent
        vector<TreeNode*> prev = getPath(parent, last[0]);
        for (int i = 1; i < last.size(); i++) {
            vector<TreeNode*> cur = getPath(parent, last[i]);
            vector<TreeNode*> nxt;
            for (int p1 = 0, p2 = 0; p1 < prev.size() && p2 < cur.size(); p1++, p2++) {
                if (prev[p1] == cur[p2]) {
                    nxt.push_back(prev[p1]);
                } else {
                    break;
                }
            }
            prev = nxt;
        }
        
        return prev.back();
    }
    
private:
    vector<TreeNode*> getPath(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* cur) {
        vector<TreeNode*> path{cur};
        while (parent[cur] != cur) {
            path.push_back(parent[cur]);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};