class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(res, n, k, to_string(i));
        }
        return res;
    }
    
private:
    void dfs(vector<int>& res, int n, int k, string cur) {
        if (cur.length() == n) {
            res.push_back(stoi(cur));
            return;
        }
        
        char last = cur.back();
        if (last - k >= '0')    dfs(res, n, k, cur + (char)(last - k));
        if (k != 0 && last + k <= '9')    dfs(res, n, k, cur + (char)(last + k));
    }
};