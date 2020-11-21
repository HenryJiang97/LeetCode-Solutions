class Solution {
    int cnt = 0;
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string sn = to_string(n);
        for (int i = 0; i < sn.length() - 1; i++) {    // Get count for number shorter than n
            cnt += pow(digits.size(), i + 1);
        }
        dfs(digits, sn, "");
        return cnt;
    }
    
private:
    void dfs(vector<string>& digits, string sn, string cur) {
        if (cur.length() == sn.length()) {
            if (cur <= sn)    cnt++;
            return;
        }
        
        for (string d : digits) {
            if (d[0] < sn[cur.length()]) {    // Current digit smaller than sn
                cnt += pow(digits.size(), sn.length() - cur.length() - 1);
            } else if (d[0] == sn[cur.length()]) {    // Current digit equal to sn
                dfs(digits, sn, cur + d);
            }
        }
    }
};