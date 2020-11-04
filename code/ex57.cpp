class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> res;
        // Find insertion position
        int p = 0;
        while (p < n && intervals[p][1] < newInterval[0]) {
            res.push_back(intervals[p++]);
        }
        
        // Merge
        int start = newInterval[0], end = newInterval[1];
        while (p < n && intervals[p][0] <= end) {    // Has intersection
            start = min(start, intervals[p][0]);
            end = max(end, intervals[p][1]);
            p++;
        }
        res.push_back({start, end});
        
        // Rest part of the intervals
        while (p < n) {
            res.push_back(intervals[p++]);
        }
        
        return res;
    }
};