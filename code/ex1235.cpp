class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++) {
            dp[i] = max(jobs[i][2], dp[i - 1]);
            int j = getj(jobs, jobs[i][1], 0, i - 1);
            if (j != -1)    dp[i] = max(dp[i], dp[j] + jobs[i][2]);
        }
        
        return dp.back();
    }
    
private:
    int getj(vector<vector<int>>& jobs, int target, int lo, int hi) {
        if (jobs[0][0] > target)    return -1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (jobs[mid][0] <= target)    lo = mid;
            else    hi = mid - 1;
        }
        return lo;
    }
};