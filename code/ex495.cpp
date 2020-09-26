class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int n = time.size();    if (n == 0)    return 0;
        int start = 0, p = 0, res = 0;
        while (p < n) {
            while (p + 1 < n && time[p] + duration >= time[p + 1])    p++;
            res += time[p] + duration - time[start];
            p++;
            start = p;
        }
        return res;
    }
};