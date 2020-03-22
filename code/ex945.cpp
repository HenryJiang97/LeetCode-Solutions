class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();    if (n == 0)    return 0;
        sort(A.begin(), A.end());
        int cnt = 0, cur = A[0] + 1;
        for (int i = 1; i < n; i++) {
            cur = max(cur, A[i]);
            cnt += cur - A[i];
            cur++;
        }
        return cnt;
    }
};