class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // Get digits array
        vector<int> arr;
        while (N > 0) {
            arr.push_back(N % 10);
            N /= 10;
        }
        reverse(arr.begin(), arr.end());
        
        // Maintain monotonously increaing stack
        stack<int> stk;
        stk.push(0);
        for (int i = 0; i < arr.size(); i++) {
            int d = arr[i];
            if (stk.top() > d) {
                // Find the last digit which can meet the monotone increasing trend
                while (stk.top() > d) {
                    d = stk.top() - 1;
                    stk.pop();
                }
                stk.push(d);
                
                // Add 9s to the end
                int size = arr.size();
                while (stk.size() < size + 1) {
                    stk.push(9);
                }
                break;
            }
            stk.push(d);
        }
        
        // Get result
        long res = 0, step = 1;
        while (!stk.empty()) {
            res += step * stk.top();
            step *= 10;
            stk.pop();
        }
        
        return (int)res;
    }
};