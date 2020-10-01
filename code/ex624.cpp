class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = INT_MAX / 2, MAX = INT_MIN / 2, res = 0;
        for (auto& array : arrays) {
            res = max(res, max(MAX - array[0], array.back() - MIN));
            MAX = max(MAX, array.back());
            MIN = min(MIN, array[0]);
        }
        return res;
    }
};