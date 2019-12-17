class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;

        for (int i = 0, k, l; i < n; i += k) {    // k => cnt of words on current line
            // Get the cnt of words on current line
            for (k = l = 0; i + k < n && k + l + words[i + k].size() <= maxWidth; k++) {
                l += words[i + k].length();
            }
            
            // Build current line
            string cur = words[i];
            for (int j = 1; j < k; j++) {
                // Adding spaces between words
                if (i + k >= n) {    // Last line => left-justified
                    cur += " ";
                } else {
                    int spaces = (maxWidth - l) / (k - 1) + (j <= (maxWidth - l) % (k - 1) ? 1 : 0);
                    cur += string(spaces, ' ');
                }
                cur += words[i + j];
            }
            cur += string(maxWidth - cur.length(), ' ');
            res.push_back(cur);
        }

        return res;
    }
};