class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();    if (n <= 1)    return true;
        
        int dict[26] = {0};
        for (int i = 0; i < order.length(); i++) {
            dict[order[i] - 'a'] = i;
        }
        
        // Find the minimum length of these words
        int min_len = INT_MAX;
        for (auto& word : words) {
            int len = word.length();
            min_len = min(min_len, len);
        }
        
        // Check if each digit of these words are sorted in lexicographicaly order
        for (int i = 1; i < n; i++) {
            // Compare words[i] and words[i - 1]
            int n1 = words[i].length(), n2 = words[i - 1].length(), p = 0;
            for (p = 0; p < min(n1, n2); p++) {
                char digit1 = dict[words[i][p] - 'a'], digit2 = dict[words[i - 1][p] - 'a'];
                if (digit1 > digit2)    break;
                else if (digit1 < digit2)    return false;
            }
            if (p == min(n1, n2) && words[i].length() < words[i - 1].length())
                return false;
        }
        
        return true;
    }
};