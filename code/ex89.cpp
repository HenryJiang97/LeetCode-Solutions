class Solution {
    int val = 0;
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        backtracking(res, n);
        return res;
    }
    
private:
    void backtracking(vector<int>& res, int n) {
        if (n == 0) {
            res.push_back(val);
            return;
        } else {
            backtracking(res, n - 1);
            val = val ^ (1 << (n - 1));
            backtracking(res, n - 1);
        }
    }
};