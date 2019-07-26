/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    TreeNode* p;
    p = root;

    if(p != NULL){
        inorderTraversal(p->left, returnSize);

        printf("%d\n", p->val);

        inorderTraversal(p->right, returnSize);
    }
    
}