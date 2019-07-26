// Greedy

class Solution {
public:
    bool checkValidString(string s) {
        int MIN = 0, MAX = 0;    // The smallest and biggest num of open bracket possible
        
        for (char c : s) {
            MIN += (c == '(') ? 1 : -1;
            MAX += (c == '(' || c == '*') ? 1 : -1;
            if (MAX < 0)    break;
            
            MIN = max(MIN, 0);
        }
        
        return MIN == 0;
    }
};