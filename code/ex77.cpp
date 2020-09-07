class Solution {
    int n;
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(n + 1);
        dfs(res, cur, visited, k);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<bool>& visited, int k) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        
        int i = cur.empty() ? 1 : cur.back() + 1;
        for (; i <= n; i++) {
            if (visited[i])    continue;
            visited[i] = 1;
            cur.push_back(i);
            dfs(res, cur, visited, k - 1);
            cur.pop_back();
            visited[i] = 0;
        }
    }
};