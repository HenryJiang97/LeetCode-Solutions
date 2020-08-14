class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')')    i++;
                else    cnt++;
                if (open == 0)    cnt++;
                else    open--;
            }
        }
        return cnt + open * 2;
    }
};