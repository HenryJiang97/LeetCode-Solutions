class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = intervals.size();
        
        vector<vector<int>> res;
        int p = 0, lo = toBeRemoved[0], hi = toBeRemoved[1];
        // Heading
        while (p < n && intervals[p][1] < lo) {
            res.push_back(intervals[p++]);
        }
        if (p >= n)    return res;
        
        // Middle
        if (intervals[p][0] < lo) {
            res.push_back({intervals[p][0], lo});
        }
        while (p < n && intervals[p][1] <= hi)    p++;
        if (p >= n)    return res;
        if (intervals[p][0] < hi) {
            res.push_back({hi, intervals[p++][1]});
        }
        
        // Ending
        while (p < n) {
            res.push_back(intervals[p++]);
        }
        
        return res;
    }
};