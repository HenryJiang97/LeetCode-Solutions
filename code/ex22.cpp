class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, n, 0, "");
        return res;
    }
    
private:
    void dfs(vector<string>& res, int open, int close, string cur) {
        if (open == 0 && close == 0) {
            res.push_back(cur);
            return;
        }
        if (open > 0)    dfs(res, open - 1, close + 1, cur + '(');
        if (close > 0)    dfs(res, open, close - 1, cur + ')');
    }
};