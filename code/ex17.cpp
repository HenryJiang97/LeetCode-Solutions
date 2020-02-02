class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")    return {};
        vector<vector<char>> dict = {{}, {}, {'a','b','c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> res;
        dfs(digits, dict, res, 0, "");
        return res;
    }
    
private:
    void dfs(string digits, vector<vector<char>>& dict, vector<string>& res, int s, string cur) {
        if (s == digits.length()) {
            res.push_back(cur);
            return;
        }
        
        for (char c : dict[digits[s] - '0']) {
            dfs(digits, dict, res, s + 1, cur + c);
        }
    }
};