class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s.push_back('0');
        vector<vector<int>> res;
        int start = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    res.push_back({start, i - 1});    
                }
                cnt = 1;
                start = i;
            }
        }
        return res;
    }
};