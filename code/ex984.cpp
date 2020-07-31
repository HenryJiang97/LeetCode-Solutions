class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        while (A > 0 || B > 0) {
            if (A >= B) {
                if (res.size() >= 2 && res.back() == 'a' && res[res.size() - 2] == 'a') {
                    res.push_back('b');
                    B--;
                } else {
                    res.push_back('a');
                    A--;
                }
            } else {
                if (res.size() >= 2 && res.back() == 'b' && res[res.size() - 2] == 'b') {
                    res.push_back('a');
                    A--;
                } else {
                    res.push_back('b');
                    B--;
                }
            }
        }
        return res;
    }
};