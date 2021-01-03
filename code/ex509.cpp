class Solution {
public:
    int fib(int n) {
        if (n <= 1)    return n;
        int p1 = 0, p = 1;
        for (int i = 2; i <= n; i++) {
            int newP = p1 + p;
            p1 = p;
            p = newP;
        }
        return p;
    }
};