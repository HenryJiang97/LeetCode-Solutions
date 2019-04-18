// Sliding window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int head = 0, end = 0;
        int max_len = 0;    // The length of the sliding window
        int unique = 0;    // Unique letter in the sliding window
        int letter[26] = {0};    // Store the number of letters in the window
        
        for (end = 0; end < s.size(); end++) {
            char c = s[end];
            unique = max(unique, ++letter[c - 'A']);
            int replacement = end - head + 1 - unique;
                
            // If the number of replacement goes over k, invalid window, move on
            if (replacement > k) {
                letter[s[head++] - 'A']--;
            }
        }
        
        return end - head;
    }
};