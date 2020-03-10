class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0)    return 0;
        int part = sum / 3;
        
        int sumi = 0;
        for (int i = 0; i < n - 2; i++) {
            sumi += A[i];
            if (sumi == part) {
                int sumj = 0;
                for (int j = i + 1; j < n - 1; j++) {
                    sumj += A[j];
                    if (sumj == part) {
                        int sumk = 0;
                        for (int k = j + 1; k < n; k++)
                            sumk += A[k];
                        if (sumk == part)    return 1;
                    }
                }
            }
        }
        return 0;
    }
};