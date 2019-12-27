class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + A[i];
        
        int res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 1; i <= n; i++) {
            int mod = prefix[i] % K;
            mod += mod < 0 ? K : 0;
            res += m[mod];
            m[mod]++;
        }
        return res;
    }
};