class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort by ending point
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        
        int prev_end = INT_MIN, res = 0;
        for (vector<int>& pair : pairs) {
            if (pair[0] > prev_end) {
                res++;
                prev_end = pair[1];
            }
        }
        
        return res;
    }
};