class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int odd = 0, even = 0, p = 0;
        while (p < n) {
            if (p % 2 == 0) {
                while (even < n && A[even] % 2 == 1)    even++;
                swap(A[p], A[even++]);
            } else {
                while (odd < n && A[odd] % 2 == 0)    odd++;
                swap(A[p], A[odd++]);
            }
            p++;
        }
        return A;
    }
};