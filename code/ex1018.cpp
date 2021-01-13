class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int cur = 0;
        for (int a : A) {
            cur = ((cur << 1) + a) % 5;
            res.push_back(cur == 0);
        }
        return res;
    }
};