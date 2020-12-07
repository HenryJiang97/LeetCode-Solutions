class Solution {
    bool valid = 0;
    int n;
public:
    vector<int> splitIntoFibonacci(string S) {
        n = S.size();
        vector<int> res;
        dfs(S, res, 0);
        return valid ? res : vector<int>();
    }
    
private:
    void dfs(string S, vector<int>& res, int s) {
        if (s >= n && res.size() >= 3) {
            valid = 1;
            return;
        }
        
        long cur = 0;
        for (int i = s; i < n; i++) {
            if (S[s] == '0' && i > s)    break;
            cur = cur * 10 + (S[i] - '0');
            if (cur > INT_MAX)    break;
            if (res.size() >= 2 && (long)res.back() + (long)res[res.size() - 2] != cur)
                continue;
            res.push_back(cur);
            dfs(S, res, i + 1);
            if (valid)    return;
            res.pop_back();
        }
    }
};