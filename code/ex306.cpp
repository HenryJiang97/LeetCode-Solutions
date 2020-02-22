class Solution {
    bool res = 0;
public:
    bool isAdditiveNumber(string num) {
        vector<unsigned long long> cur;
        backtracking(num, cur, 0);
        return res;
    }
    
private:
    void backtracking(string num, vector<unsigned long long>& cur, int s) {
        if (s == num.length()) {
            if (cur.size() >= 3 && cur[cur.size() - 3] + cur[cur.size() - 2] == cur.back())
                res = 1;
            return;
        }
        
        unsigned long long n = 0;
        for (int i = s; i < num.length(); i++) {
            n = n * 10 + (num[i] - '0');
            if (i != s && num[s] == '0')    continue;
            if (cur.size() >= 2 && cur[cur.size() - 2] + cur.back() != n)    continue;
            cur.push_back(n);
            backtracking(num, cur, i + 1);
            if (res)    return;
            cur.pop_back();
        }
    }
};