class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        long num = (long)n;
        while (num != 1) {
            if (num % 2 == 0)    num = num >> 1;
            else {
                if (num == 3 || __builtin_popcount(num + 1) > __builtin_popcount(num - 1)) {
                    num--;
                } else {
                    num++;
                }
            }
            cnt++;
        }
        return cnt;
    }
};