class Solution {
public:
    bool checkValidString(string s) {
        int MAX = 0, MIN = 0;    // The maximum and minimum number of open brackets
        for (char c : s) {
            if (c == '(') {
                MAX++;    MIN++;
            } else if (c == ')') {
                if (MAX == 0)    return 0;
                MAX--;
                if (MIN > 0)    MIN--;
            } else {
                MAX++;
                if (MIN > 0)    MIN--;
            }
        }
        return MIN == 0;
    }
};