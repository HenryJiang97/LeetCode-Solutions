class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, k, n, 1);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int k, int n, int s) {
        if (k == 0) {
            if (n == 0)    res.push_back(cur);
            return;
        }
        
        for (int i = s; i <= 9; i++) {
            cur.push_back(i);
            dfs(res, cur, k - 1, n - i, i + 1);
            cur.pop_back();
        }
    }
};