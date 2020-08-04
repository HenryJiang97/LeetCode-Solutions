class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> left(26, n), right(26, -1);
        for (int i = 0; i < n; i++) {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = max(right[s[i] - 'a'], i);
        }
        
        // Function to extend current substring to the right
        auto extend = [&](int i) -> int {
            int r = right[s[i] - 'a'];
            for (int j = i + 1; j <= r; j++) {
                if (left[s[j] - 'a'] < i)    return -1;    // Invalid
                r = max(r, right[s[j] - 'a']);
            }
            return r;
        };
        
        vector<string> res;
        int prevEnd = -1;
        for (int i = 0; i < n; i++) {
            if (left[s[i] - 'a'] != i)    continue;    // Current char not starting at this position
            int end = extend(i);
            if (end == -1)    continue;    // Invalid
            if (end > prevEnd)    res.push_back("");
            res.back() = s.substr(i, end - i + 1);
            prevEnd = end;
        }
        
        return res;
    }
};