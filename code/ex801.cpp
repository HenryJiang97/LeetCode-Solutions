// DP

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        // Define dp arrays, the minimum swaps till current position if swap or not swap current position
        vector<int> swap(n, INT_MAX), notSwap(n, INT_MAX);
        swap[0] = 1;    notSwap[0] = 0;
        
        // Build dp arrays
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {    // No need to swap at this position
                notSwap[i] = notSwap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {    // Need to swap at this position
                notSwap[i] = min(notSwap[i], swap[i - 1]);
                swap[i] = min(swap[i], notSwap[i - 1] + 1);
            }
        }
        
        return min(swap[n - 1], notSwap[n - 1]);
    }
};