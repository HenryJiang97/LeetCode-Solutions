class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int MIN = n, before = -1, idx = -1;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) {
                if (before == -1 || before == 1 && word1 != word2) {
                    before = 1;
                    idx = i;
                } else {
                    MIN = min(MIN, i - idx);
                    before = 1;
                    idx = i;
                }
            }
            else if (words[i] == word2) {
                if (before == -1 || before == 2 && word1 != word2) {
                    before = 2;
                    idx = i;
                } else {
                    MIN = min(MIN, i - idx);
                    before = 2;
                    idx = i;
                }
            }
        }
        return MIN;
    }
};