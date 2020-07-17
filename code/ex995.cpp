class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), flips = 0, cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (i - K >= 0 && A[i - K] == 2) {    // End prev sliding window
                flips--;
            }
            if (A[i] == flips % 2) {    // Current position needs to be fliped
                if (i + K > n)    return -1;
                A[i] = 2;    // Flag, fliped at this position
                flips++;    cnt++;
            }
        }
        
        return cnt;
    }
};