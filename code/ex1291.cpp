class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; i++)
            dfs(low, high, res, i);
        sort(res.begin(), res.end());
        return res;
    }
    
private:
    void dfs(long low, long high, vector<int>& res, long cur) {
        if (cur >= low && cur <= high)    res.push_back(cur);
        if (cur > high)    return;
        int lastD = cur % 10;
        if (lastD + 1 <= 9) {
            dfs(low, high, res, cur * 10 + lastD + 1);
        }
    }
};