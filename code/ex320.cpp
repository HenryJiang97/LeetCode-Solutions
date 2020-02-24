class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtracking(word, res, 0, "");
        return res;
    }

private:
    void backtracking(string word, vector<string>& res, int s, string cur) {
        if (s >= word.length()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i <= word.length() - s; i++) {
            string newS = i == 0 ? cur + word[s] : cur + to_string(i);
            // Add the next char following by a number
            if (i != 0 && s + i < word.length())    newS += word[s + i];
            int nxtIdx = s + i + 1;
            backtracking(word, res, nxtIdx, newS);
        }
    }
};