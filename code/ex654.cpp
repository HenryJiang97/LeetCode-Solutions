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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi)    return NULL;
        
        // Find the node with max value and its index in nums
        int MAX = INT_MIN, idx = -1;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] > MAX) {
                MAX = nums[i];
                idx = i;
            }
        }
        
        // Build node
        TreeNode* root = new TreeNode(MAX);
        root->left = helper(nums, lo, idx - 1);
        root->right = helper(nums, idx + 1, hi);
        
        return root;
    }
};