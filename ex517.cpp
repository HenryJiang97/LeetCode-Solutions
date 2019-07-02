// DP, dp[i] => Number of dresses i machine needs to pass out

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n != 0)    return -1;
        int avg = sum / n;
        
        int dp[n] = {0};
        for (int i = 0; i < n - 1; i++) {
            if (machines[i] > avg)    dp[i] += machines[i] - avg;
            else if (machines[i] < avg)    dp[i + 1] = avg - machines[i];
            
            machines[i + 1] += machines[i] - avg;
        }
        
        int res = INT_MIN;
        for (auto a : dp)    res = max(res, a);
        
        return res;
    }
};