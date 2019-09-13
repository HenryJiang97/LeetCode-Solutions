class Solution {
    int i = 0;
    
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                i++;
                int ret = recurrsion(s);
                score += ret == 0 ? 1 : 2 * ret;
            }
        }
        return score;
    }
    
private:
    int recurrsion(string s) {
        int score = 0;
        
        while (i < s.length()) {
            if (s[i] == '(') {
                i++;
                int ret = recurrsion(s);
                score += ret == 0 ? 1 : 2 * ret;
            }
            else if (s[i] == ')') {
                i++;
                return score;
            }
        }
        return score;
    }
};