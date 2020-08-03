class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N; i > N / 2; i--) {
            string bit = bitset<32>(i).to_string();
            if (!has(S, bit.substr(bit.find('1'))))
                return 0;
        }
        return 1;
    }
    
private:
    bool has(string S, string s) {
        int nS = S.length(), ns = s.length();
        for (int i = 0; i <= nS - ns; i++) {
            if (S.substr(i, ns) == s)    return 1;
        }
        return 0;
    }
};