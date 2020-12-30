class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] != b[1] ? a[1] < b[1] : a[1] - a[0] < b[1] - b[0];
        });
        
        int fit = 0, end = INT_MIN;
        for (auto& interval : intervals) {
            if (interval[0] >= end) {
                end = max(end, interval[1]);
                fit++;
            }
        }
        
        return intervals.size() - fit;
    }
};