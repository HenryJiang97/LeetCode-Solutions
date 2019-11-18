class Solution {
public:
    int reachNumber(int target) {
        if (target == 0)    return 0;
        target = abs(target);
        int t = 0, i = 1;
        while (1) {
            t += i;
            if (t >= target)    break;
            i++;
        }
        int over = i * (i + 1) / 2 - target;
        if (over % 2 == 0)    return i;
        return i % 2 == 0 ? i + 1 : i + 2;
    }
};