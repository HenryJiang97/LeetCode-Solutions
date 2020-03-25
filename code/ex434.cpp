class Solution {
public:
    int countSegments(string s) {
        s += " ";
        int cnt = 0;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                if (temp != "")    cnt++;
                temp = "";
            }
            else
                temp += c;
        }
        return cnt;
    }
};