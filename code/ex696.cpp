class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), cnt = 0;
        
        int cur = 0, prev = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i])    j++;
            cur = j - i;
            i = j;
            cnt += min(cur, prev);
            prev = cur;
        }
        
        return cnt;
    }
};