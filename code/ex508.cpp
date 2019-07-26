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
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL)    return {};
        
        map<int, int, greater<int>> map;
        
        // Run dfs
        int sum = dfs(root->left, map) + dfs(root->right, map) + root->val;
        if (map.find(sum) != map.end())    map[sum]++;
        else    map[sum] = 1;
        
        // Get most frequent sum
        int MAX = INT_MIN;
        for (auto entry : map) {
            if (entry.second > MAX)
                MAX = entry.second;
        }
        
        // Get result
        vector<int> res;
        for (auto entry : map) {
            if (entry.second == MAX)
                res.push_back(entry.first);
        }
        
        return res;
    }
    
private:
    int dfs(TreeNode* root, auto& map) {
        TreeNode* p = root;
        if (p == NULL)    return 0;
        
        int sum = dfs(p->left, map) + dfs(p->right, map) + p->val;
        
        if (map.find(sum) != map.end())    map[sum]++;
        else    map[sum] = 1;
        
        return sum;
    }
};