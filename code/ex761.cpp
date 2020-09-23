class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, n = S.length(), i = 0;
        vector<string> strs;
        for (int j = 0; j < n; j++) {
            if (S[j] == '1')    cnt++;
            else    cnt--;
            if (cnt == 0) {
                strs.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(strs.begin(), strs.end(), greater<string>());
        
        // Combine
        string res = "";
        for (string str : strs)    res += str;
        return res;
    }
};