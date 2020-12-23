class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for (int i = 0; i < n + 1; i++) {
            intervals.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] - a[0] > b[1] - b[0];
        });
        
        int p = 0, prev = 0, cnt = 0;
        while (prev < n && p < intervals.size()) {
            if (intervals[p][0] > prev)    return -1;
            int MAX = 0, i = p;
            while (i < n && intervals[i][0] <= prev) {
                MAX = max(MAX, intervals[i++][1]);
            }
            cnt++;
            prev = MAX;
            p = i;
        }
        if (prev < n)    return -1;
        
        return cnt;
    }
};