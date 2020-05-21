class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int xmin = m, ymin = n;
        for (auto& op : ops) {
            xmin = min(xmin, op[0]);
            ymin = min(ymin, op[1]);
        }
        return xmin * ymin;
    }
};