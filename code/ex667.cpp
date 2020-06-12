class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int lo = 1, hi = n; lo <= hi; ) {
            if (k > 0)
                res.push_back(k-- % 2 == 1 ? lo++ : hi--);
            else
                res.push_back(lo++);
        }
        return res;
    }
};