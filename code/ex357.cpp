class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)    return 1;
        int total = 9, cnt = 9;
        for (int i = 2; i <= n; i++) {
            int choice = 9 - i + 2;
            cnt *= choice;
            total += cnt;
        }
        return total + 1;
    }
};