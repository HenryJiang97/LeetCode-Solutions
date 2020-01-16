class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        for (string word : words)
            if (valid(S, word))    cnt++;
        return cnt;
    }
    
private:
    bool valid(string s, string w) {
        int ns = s.length(), nw = w.length();
        int slowi = 0, fasti = 0, slowj = 0, fastj = 0;
        while (slowi < ns && slowj < nw) {
            if (s[slowi] != w[slowj])    return 0;
            while (fasti < ns && s[fasti] == s[slowi])    fasti++;
            while (fastj < nw && w[fastj] == w[slowj])    fastj++;
            if ((fasti - slowi != fastj - slowj) && ((fasti - slowi < 3) || (fasti - slowi < fastj - slowj)))
                return 0;
            slowi = fasti;    slowj = fastj;
        }
        return slowi == ns && slowj == nw;
    }
};