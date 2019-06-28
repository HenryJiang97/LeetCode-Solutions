/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int MAX = 1, last = INT_MIN;
public:
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)    return {};
        vector<int> res;
        int cnt = 1;
        findmax(root, cnt, res);
        
        if (cnt > MAX) {
            res.clear();
            res.push_back(last);
            MAX = cnt;
        } else if (cnt == MAX) {
            res.push_back(last);
        }
        
        return res;
    }
    
private:
    void findmax(TreeNode* root, int& cnt, vector<int>& res) {
        TreeNode* p = root;
        if (p == NULL)    return;
        
        findmax(p->left, cnt, res);
        
        // In place maintaining the result array
        if (p->val == last) {
            cnt++;
        } else {
            if (last == INT_MIN)    last = p->val;
            else {
                if (cnt > MAX) {
                    res.clear();
                    res.push_back(last);
                    MAX = cnt;
                } else if (cnt == MAX)
                    res.push_back(last);
        
                cnt = 1;    last = p->val;
            }
        }
        
        findmax(p->right, cnt, res);
    }
};