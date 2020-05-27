class Solution {
public:
    string boldWords(vector<string>& dict, string s) {
        unordered_set<string> set(dict.begin(), dict.end());
        
        // Get bold intervals
        vector<vector<int>> intervals;
        for (int i = 0; i < s.length(); i++) {
            string temp = "";
            for (int j = i; j < s.length(); j++) {
                temp += s[j];
                if (set.find(temp) != set.end())
                    intervals.push_back({i, j});
            }
        }
        if (intervals.size() == 0)    return s;
        
        // Merge intervals
        vector<vector<int>> boldIntervals;
        int lo = intervals[0][0], hi = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= hi + 1)
                hi = max(hi, intervals[i][1]);
            else {
                boldIntervals.push_back({lo, hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        }
        boldIntervals.push_back({lo, hi});
        
        // Get result
        string res = "";
        int prev = 0;
        for (auto& bi : boldIntervals) {
            res += s.substr(prev, bi[0] - prev);
            res += "<b>" + s.substr(bi[0], bi[1] - bi[0] + 1) + "</b>";
            prev = bi[1] + 1;
        }
        if (prev < s.length())    res += s.substr(prev);
        
        return res;
    }
};