class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto& domino : dominoes) {
            int hcode = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            res += cnt[hcode];
            cnt[hcode]++;
        }
        return res;
    }
};