class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();    if (n < 3)    return 0;
        bool downHill = 0;
        int prev = A[0];
        for (int i = 1; i < n; i++) {
            if (prev == A[i])    return 0;
            if (downHill) {
                if (prev < A[i])    return 0;
            } else {
                if (prev > A[i]) {
                    if (i == 1)    return 0;
                    downHill = 1;
                }
            }
            prev = A[i];
        }
        return downHill;
    }
};