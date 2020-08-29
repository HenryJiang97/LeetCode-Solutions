class Solution {
public:
    string reverseWords(string s) {
        string res = "", temp = "";
        s += " ";
        int i = 0;
        for (char c : s) {
            if (c == ' ') {
                reverse(temp.begin(), temp.end());
                if (i != 0)    res += " ";
                res += temp;
                temp = "";
                i++;
            } else {
                temp += c;
            }
        }
        return res;
    }
};