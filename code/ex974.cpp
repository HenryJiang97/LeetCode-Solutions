class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int prefix = 0, cnt = 0;
        unordered_map<int, int> modArr;
        modArr[0] = 1;
        for (int i = 0; i < A.size(); i++) {
            prefix += A[i];
            int modi = (prefix % K + K) % K;    // Avoid negative modulo
            cnt += modArr[modi];
            modArr[modi]++;
        }
        return cnt;
    }
};