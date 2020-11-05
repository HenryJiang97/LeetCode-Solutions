class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int na = __builtin_popcount(a), nb = __builtin_popcount(b);
            return na != nb ? na < nb : a < b;
        });
        return arr;
    }
};