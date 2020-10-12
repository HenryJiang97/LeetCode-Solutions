class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        
        // Build prefix sum
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + A[i];
        
        int MIN = n + 1;
        deque<int> dque;
        dque.push_back(0);
        for (int i = 0; i < n; i++) {
            // Remove from tail which prefix before is larger than current prefix
            while (!dque.empty() && prefix[dque.back()] > prefix[i + 1])
                dque.pop_back();
            
            // Remove from head which prefix difference meets the requirement
            while (!dque.empty() && prefix[i + 1] - prefix[dque.front()] >= K) {
                MIN = min(MIN, i + 1 - dque.front());
                dque.pop_front();
            }
            
            dque.push_back(i + 1);
        }
        
        return MIN > n ? -1 : MIN;
    }
};