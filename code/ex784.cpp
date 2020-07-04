class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, res, 0, "");
        return res;
    }
    
private:
    void dfs(string s, vector<string>& res, int i, string cur) {
        if (i >= s.length()) {
            res.push_back(cur);
            return;
        }
        if (isalpha(s[i])) {
            dfs(s, res, i + 1, cur + (char)tolower(s[i]));
            dfs(s, res, i + 1, cur + (char)toupper(s[i]));
        } else {
            dfs(s, res, i + 1, cur + s[i]);
        }
    }
};