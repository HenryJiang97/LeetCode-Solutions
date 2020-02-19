class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)    return 0;
        if (n == 1)    return k;
        if (n == 2)    return k * k;
        int prev = k * k, prev2 = k;
        for (int i = 2; i < n; i++) {
            int temp = prev;
            prev = (k - 1) * (prev + prev2);
            prev2 = temp;
        }
        return prev;
    }
};