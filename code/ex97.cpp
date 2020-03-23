class Solution {
    string s1, s2, s3;
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;    this->s2 = s2;    this->s3 = s3;
        vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1));
        return backtracking(0, 0, 0, memo);
    }

private:
    bool backtracking(int p1, int p2, int p3, vector<vector<int>>& memo) {
        if (p1 == s1.length() && p2 == s2.length() && p3 == s3.length())    return 1;
        if (p1 >= s1.length() && p2 >= s2.length() && p3 < s3.length())    return 0;
        if (p3 >= s3.length() && (p1 < s1.length() || p2 < s2.length()))    return 0;
        
        if (memo[p1][p2] != 0)    return memo[p1][p2] == 1 ? 1 : 0;
        
        bool res = 0;
        if (s1[p1] == s3[p3])
            res |= backtracking(p1 + 1, p2, p3 + 1, memo);
        if (s2[p2] == s3[p3])
            res |= backtracking(p1, p2 + 1, p3 + 1, memo);
        
        memo[p1][p2] = res ? 1 : -1;
        return res;
    }
};