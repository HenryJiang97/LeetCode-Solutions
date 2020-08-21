// sum = A[i] * (1 + left_span + right_span + (left_span * right_span))
// Maintaining monotone ascending stack

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int mod = 1e9 + 7, n = A.size();
        
        stack<int> stk;
        vector<int> left(n), right(n);
        
        // Get left span
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && A[stk.top()] >= A[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? i : i - stk.top() - 1;
            stk.push(i);
        }
        
        // Get right span
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && A[stk.top()] > A[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n - i - 1 : stk.top() - i - 1;
            stk.push(i);
        }
        
        // Get sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (1 + left[i] + right[i] + left[i] * right[i]) * A[i];
            sum %= mod;
        }
        
        return sum;
    }
};