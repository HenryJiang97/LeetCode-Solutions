const int mod = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        if (n == 0)    return 1;
        
        // With As before
        long dp1 = 0;    // End with no L
        long dp2 = 0;    // End with one L
        long dp3 = 0;    // End with two continuous Ls
        
        // With no A before
        long dp4 = 1;    // End with no L
        long dp5 = 0;    // End with one L
        long dp6 = 0;    // End with two continuous Ls
        
        for (int i = 1; i <= n; i++) {
            long p1 = dp1, p2 = dp2, p3 = dp3, p4 = dp4, p5 = dp5, p6 = dp6;
            dp1 = (p1 + p2 + p3 + p4 + p5 + p6) % mod;
            dp2 = p1;
            dp3 = p2;
            dp4 = (p4 + p5 + p6) % mod;
            dp5 = p4;
            dp6 = p5;
        }
        
        return (dp1 + dp2 + dp3 + dp4 + dp5 + dp6) % mod;
    }
};