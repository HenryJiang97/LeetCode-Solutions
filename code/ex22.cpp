class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(n, n, res, "");
        return res;
    }
    
private:
    void backtracking(int l, int r, vector<string>& res, string s) {
        if (l == 0 && r == 0) {
            res.push_back(s);
            return;
        }
        if (l < 0 || r < 0 || l > r)    return;
        
        // Pick left bracket
        backtracking(l - 1, r, res, s + "(");
        // Pick right bracket
        backtracking(l, r - 1, res, s + ")");
    }
};