class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {    // O(N * (2 ^ N))
        vector<string> arr{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        unordered_set<string> dp(arr.begin(), arr.end());
        for (int i = 2; i <= N; i++) {
            unordered_set<string> temp;
            for (string s : dp) {
                char chead = s[0], cend = s.back();
                for (char c = '0'; c <= '9'; c++) {
                    if (c != '0' && (c + K == chead || c - K == chead))    temp.insert(c + s);
                    if (chead != '0' && (c + K == cend || c - K == cend))    temp.insert(s + c);
                }
            }
            dp = temp;
        }
        vector<int> res;
        for (string s : dp)    res.push_back(stoi(s));
        return res;
    }
};