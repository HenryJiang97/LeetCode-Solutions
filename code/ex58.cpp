class Solution {
public:
    int lengthOfLastWord(string s) {
        s += ' ';
        int temp = 0, len = 0;
        for (char c : s) {
            if (c == ' ') {
                if (temp > 0)    len = temp;
                temp = 0;
            } else {
                temp++;
            }
        }
        return len;
    }
};