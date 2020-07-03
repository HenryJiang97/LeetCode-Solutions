const long mod = 1e9 + 7;

class Solution {
public:
    int numTilings(int N) {
        vector<long> dp0(N + 1);    // Both top and bottom squares have been occupied
        vector<long> dp1(N + 1);    // Only bottom square has been occupied
        vector<long> dp2(N + 1);    // Only top square has been occupied
        dp0[0] = 1;
        for (int i = 1; i <= N; i++) {
            dp0[i] = (dp0[i - 1] + dp1[i - 1] + dp2[i - 1] + (i - 2 >= 0 ? dp0[i - 2] : 0)) % mod;
            dp1[i] = (dp2[i - 1] + (i - 2 >= 0 ? dp0[i - 2] : 0)) % mod;
            dp2[i] = ((i - 2 >= 0 ? dp0[i - 2] : 0) + dp1[i - 1]) % mod;
        }
        return (int)dp0.back();
    }
};