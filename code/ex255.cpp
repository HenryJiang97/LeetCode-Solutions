class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        
        stack<int> stk;
        int root = INT_MIN;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && preorder[i] > stk.top()) {
                root = stk.top();
                stk.pop();
            }
            if (preorder[i] < root)    return 0;
            stk.push(preorder[i]);
        }
        
        return 1;
    }
};