class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> left;
        for (int i = 0; i < n; i++) {
            left.push_back({intervals[i][0], i});
        }
        sort(left.begin(), left.end());
        
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = bs(left, intervals[i][1]);
        }
        
        return res;
    }
    
private:
    int bs(vector<pair<int, int>>& left, int target) {
        if (left.back().first < target)    return -1;
        int lo = 0, hi = left.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (left[mid].first >= target)    hi = mid;
            else    lo = mid + 1;
        }
        return left[hi].second;
    }
};