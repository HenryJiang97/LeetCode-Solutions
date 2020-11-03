class Solution {
public:
    int maxPower(string s) {
        s += ' ';
        int n = s.length(), MAX = 1;
        char prev = s[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == prev) {
                cnt++;
            } else {
                MAX = max(MAX, cnt);
                cnt = 1;
                prev = s[i];
            }
        }
        return MAX;
    }
};