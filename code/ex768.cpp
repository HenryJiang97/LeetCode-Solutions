class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // Get minSuffix for min elements on the right of i
        vector<int> minSuffix(n);
        minSuffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            minSuffix[i] = min(minSuffix[i + 1], arr[i]);
        
        int res = 0, maxPrefix = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            maxPrefix = i == 0 ? arr[i] : max(maxPrefix, arr[i]);
            if (maxPrefix <= minSuffix[i + 1])    res++;
        }
        
        return res + 1;
    }
};