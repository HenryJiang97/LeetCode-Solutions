class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        int MAX = 1;
        vector<int> dp(n, 1);
        unordered_map<int, int> map;
        map[arr[0]] = 1;
        for (int i = 1; i < n; i++) {
            map[arr[i]] = max(map[arr[i]], map[arr[i] - difference] + 1);
            MAX = max(MAX, map[arr[i]]);
        }
        
        return MAX;
    }
};