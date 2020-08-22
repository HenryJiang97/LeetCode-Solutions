class Solution {
    vector<int> points{0};
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int mask = 0;
        for (auto& rect : rects) {
            mask += (rect[3] - rect[1] + 1) * (rect[2] - rect[0] + 1);
            points.push_back(mask);
        }
    }
    
    vector<int> pick() {
        int r = rand() % points.back();    // Get random number in [0, points.back())
        int idx = find(points.begin(), points.end(), *upper_bound(points.begin(), points.end(), r)) - points.begin();
        vector<int> rect = rects[idx - 1];
        int x = rect[2] - rect[0] + 1;
        return {(r - points[idx - 1]) % x + rect[0], (r - points[idx - 1]) / x + rect[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */