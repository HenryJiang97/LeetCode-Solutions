class Solution {
public:
    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(27, vector<int>(27)));
        int MIN = INT_MAX;
        return helper(word, 1, word[0], '[', memo);
        return MIN;
    }
    
private:
    int helper(string word, int s, char left, char right, vector<vector<vector<int>>>& memo) {
        if (s >= word.length())    return 0;
        if (memo[s][left - 'A'][right - 'A'] != 0)    return memo[s][left - 'A'][right - 'A'];
        int MIN = INT_MAX;
        
        if (right == '[')    MIN = min(MIN, helper(word, s + 1, left, word[s], memo));
        else    MIN = min(MIN, helper(word, s + 1, left, word[s], memo) + getDis(right, word[s]));
        MIN = min(MIN, helper(word, s + 1, word[s], right, memo) + getDis(left, word[s]));
        
        memo[s][left - 'A'][right - 'A'] = MIN;
        return MIN;
    }
    
    int getDis(char a, char b) {
        int ia = (a - 'A') / 6, ja = (a - 'A') % 6;
        int ib = (b - 'A') / 6, jb = (b - 'A') % 6;
        return abs(ia - ib) + abs(ja - jb);
    }
};