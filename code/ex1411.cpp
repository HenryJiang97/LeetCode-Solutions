class Solution {
    int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        if (n == 1)    return 12;
        
        vector<int> dp(27);
        for (int mask = 0; mask < 27; mask++) {
            if (validRow(mask))    dp[mask] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            vector<int> newDp(27);
            for (int cur = 0; cur < 27; cur++) {
                if (!validRow(cur))    continue;
                for (int prev = 0; prev < 27; prev++) {
                    if (!validRow(prev))    continue;
                    bool valid = 1;
                    if (validCol(prev, cur)) {
                        newDp[cur] = (newDp[cur] + dp[prev]) % mod;
                    }
                }
            }
            dp = newDp;
        }
        
        // Get result
        int res = 0;
        for (int mask = 0; mask < 27; mask++) {
            res = (res + dp[mask]) % mod;
        }
        
        return res;
    }
    
private:
    bool validRow(int mask) {
        int a = mask % 3;    mask /= 3;
        int b = mask % 3;    mask /= 3;
        int c = mask % 3;
        return a != b && b != c;
    }
    
    bool validCol(int prev, int cur) {
        int pa = prev % 3;    prev /= 3;
        int pb = prev % 3;    prev /= 3;
        int pc = prev % 3;
        int ca = cur % 3;    cur /= 3;
        int cb = cur % 3;    cur /= 3;
        int cc = cur % 3;
        return pa != ca && pb != cb && pc != cc;
    }
};