class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        word += ' ';    abbr += ' ';
        int nw = word.length(), na = abbr.length();
        int pw = 0, pa = 0, cnt = 0;
        while (pw < nw && pa < na) {
            if (abbr[pa] >= '0' && abbr[pa] <= '9') {
                if (abbr[pa] == '0' && cnt == 0)    return 0;
                cnt = cnt * 10 + (abbr[pa++] - '0');
            } else {
                pw += cnt;
                if (pw >= nw)    return 0;
                if (word[pw++] != abbr[pa++])    return 0;
                cnt = 0;
            }
        }
        return pw == nw && pa == na;
    }
};