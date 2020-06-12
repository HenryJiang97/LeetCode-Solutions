class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int lo = 1, hi = n; lo <= hi; ) {
            if (k > 0)
                // Put lo and hi alternatively
                res.push_back(k-- % 2 == 1 ? lo++ : hi--);
            else
                // Add rest nums
                res.push_back(lo++);
        }
        return res;
    }
};