class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int p = 0;
        while (p < n && intervals[p][1] < newInterval[0])
            res.push_back(intervals[p++]);
        if (p >= n) {
            res.push_back(newInterval);
            return res;
        }
        
        int lo = min(intervals[p][0], newInterval[0]), hi = newInterval[1];
        while (p < n && intervals[p][0] <= newInterval[1]) {
            hi = max(hi, intervals[p++][1]);
        }
        res.push_back({lo, hi});
        
        while (p < n)    res.push_back(intervals[p++]);
        return res;
    }
};