class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size();
        int cnt = 0;
        
        vector<bool> prev(m);    // If the prev string is absolutely smaller than cur till current char
        for (int j = 0; j < n; j++) {
            bool valid = 1;
            for (int i = 1; i < m; i++) {
                if (!prev[i] && A[i][j] < A[i - 1][j])    valid = 0;
            }
            
            if (!valid)    cnt++;    // Delete current column
            else {
                for (int i = 1; i < m; i++) {
                    if (A[i][j] > A[i - 1][j])    prev[i] = 1;
                }
            }
        }
        
        return cnt;
    }
};