class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtracking(res, cur, s, 0);
        return res;
    }
    
private:
    void backtracking(vector<vector<string>>& res, vector<string>& cur, string s, int p) {
        if (p >= s.length()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = p; i < s.length(); i++) {
            string ss = s.substr(p, i - p + 1);
            if (isPalindrome(ss)) {
                cur.push_back(ss);
                backtracking(res, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--])
                return 0;
        }
        return 1;
    }
};