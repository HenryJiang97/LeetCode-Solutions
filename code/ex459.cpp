class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int partition = 2; partition <= n; partition++) {
            if (n % partition != 0)    continue;
            bool sign = true;
            int interval = n / partition;
            for (int i = 0; i < interval; i++) {
                for (int j = i + interval; j < n; j += interval) {
                    if (s[i] != s[j]) {
                        sign = false;
                        break;
                    }
                }
                if (!sign)    break;
            }
            if (sign)    return true;
        }
        return false;
    }
};