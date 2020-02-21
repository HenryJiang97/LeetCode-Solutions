class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        long cur = 0;
        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[0] == '0')    break;
            cur = cur * 10 + (num[i] - '0');
            string curStr = to_string(cur);
            dfs(res, num, target, cur, cur, curStr, i + 1);
        }
        return res;
    }
    
private:
    void dfs(vector<string>& res, string num, int target, long sum, long multiply, string oper, int s) {
        if (s == num.length()) {
            if (sum == target) {
                res.push_back(oper);
            }
            return;
        }
        
        for (int i = s; i < num.length(); i++) {
            if (i != s && num[s] == '0')    return;
            string nstr = num.substr(s, i - s + 1);
            int n = stoi(nstr);
            // +
            dfs(res, num, target, sum + n, n, oper + '+' + nstr, i + 1);
            // -
            dfs(res, num, target, sum - n, -n, oper + '-' + nstr, i + 1);
            // *
            dfs(res, num, target, sum - multiply + multiply * n, multiply * n, oper + '*' + nstr, i + 1);    
        }
        
    }
};