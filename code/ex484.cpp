class Solution {
public:
    vector<int> findPermutation(string s) {
        s = 'I' + s;
        int n = s.length();
        vector<int> res(n);
        for (int i = 1; i <= n; i++)    res[i - 1] = i;
        int I;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                if (i - 1 >= 0 && s[i - 1] == 'D')    invert(res, I, i - 1);
                I = i;
            }
        }
        if (n - 1 >= 0 && s[n - 1] == 'D')    invert(res, I, n - 1);
        return res;
    }
    
private:
    void invert(vector<int>& res, int lo, int hi) {    // Inverse the num sequence within [lo, hi]
        while (lo < hi) {
            int temp = res[lo];
            res[lo] = res[hi];
            res[hi] = temp;
            lo++;    hi--;
        }
    }
};