class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        
        // Reverse all chars
        int lo = 0, hi = n - 1;
        while (lo < hi)    swap(s[lo++], s[hi--]);
        
        // Reverse each single word
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                lo = prev;    hi = i - 1;
                while (lo < hi)    swap(s[lo++], s[hi--]);
                prev = i + 1;
            }
        }
        
        // Ending
        lo = prev;    hi = n - 1;
        while (lo < hi)    swap(s[lo++], s[hi--]);
    }
};