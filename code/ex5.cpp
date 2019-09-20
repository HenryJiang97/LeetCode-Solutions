class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();    if (n == 0)    return "";
        
        string res = "";
        int i = 0;
        while (i < n) {
            int left = i, right = i;
            
            // Find duplicate chars for middle part of the palidrom
            while (right + 1 < n && s[right] == s[right + 1])    ++right;
            
            i = right + 1;
            
            // Expand the palidrom
            while (left - 1 >= 0 && right + 1 < n && s[left - 1] == s[right + 1]) {
                left--;    right++;
            }
            
            // Record the palidrom
            if (right - left + 1 > res.length())
                res = s.substr(left, right - left + 1);
        }
        
        return res;
    }
};