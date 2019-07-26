// Greedy
struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();    if (n == 0)    return 0;
        sort(points.begin(), points.end(), cmp());
        
        int cnt = 0, i = 0, last = points[0][1];
        while (i < n) {
            cnt++;    last = points[i][1];
            while (i < n && points[i][0] <= last)    i++;
        }
        
        return cnt;
    }
};