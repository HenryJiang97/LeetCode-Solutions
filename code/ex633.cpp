class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i * i <= c / 2; i++) {
            int target = c - i * i;
            if ((int)sqrt(target) * (int)sqrt(target) == target)
                return 1;
        }
        return 0;
    }
};