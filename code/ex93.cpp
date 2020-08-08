class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12)    return {};
        vector<string> res;
        dfs(s, res, 0, "", 0);
        return res;
    }
    
private:
    void dfs(string s, vector<string>& res, int start, string cur, int cnt) {
        if (start >= s.length()) {
            if (cnt == 4)    res.push_back(cur.substr(0, cur.length() - 1));
            return;
        }
        
        if (s[start] == '0') {
            dfs(s, res, start + 1, cur + "0.", cnt + 1);
        } else {
            for (int i = start; i < s.length(); i++) {
                string substring = s.substr(start, i - start + 1);
                long val = stol(substring);
                if (val >= 0 && val <= 255) {
                    dfs(s, res, i + 1, cur + substring + ".", cnt + 1);
                }
            }
        }
    }
};