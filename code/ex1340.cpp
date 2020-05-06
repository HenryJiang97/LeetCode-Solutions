class Solution {
    int n, d;
public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        this->d = d;
        
        int MAX = 0;
        vector<int> memo(n);
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, dfs(arr, i, memo));
        }
        return MAX;
    }
    
private:
    int dfs(vector<int>& arr, int s, vector<int>& memo) {
        if (memo[s] != 0)    return memo[s];
        
        int MAX = 1;
        for (int i = 1; i <= d && s - i >= 0; i++) {    // Go left
            if (arr[s - i] >= arr[s])    break;
            MAX = max(MAX, dfs(arr, s - i, memo) + 1);
        }
        for (int i = 1; i <= d && s + i < n; i++) {    // Go right
            if (arr[s + i] >= arr[s])    break;
            MAX = max(MAX, dfs(arr, s + i, memo) + 1);
        }
        
        memo[s] = MAX;
        return MAX;
    }
};