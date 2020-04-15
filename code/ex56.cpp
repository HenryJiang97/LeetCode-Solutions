class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();    if (n == 0)    return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int p = 1, start = intervals[0][0], end = intervals[0][1];
        while (p < n) {
            while (p < n && intervals[p][0] <= end) {
                end = max(end, intervals[p++][1]);
            }
            res.push_back({start, end});
            start = p < n ? intervals[p][0] : INT_MAX;
            end = p < n ? intervals[p++][1] : INT_MAX;
        }
        if (start != INT_MAX)    res.push_back({start, end});
        return res;
    }
};