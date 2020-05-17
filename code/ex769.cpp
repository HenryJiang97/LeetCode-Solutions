class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> maxPrefix(n), minSuffix(n);
        maxPrefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            maxPrefix[i] = max(maxPrefix[i - 1], arr[i]);
        minSuffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            minSuffix[i] = min(minSuffix[i + 1], arr[i]);
        
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (maxPrefix[i] <= minSuffix[i + 1])    res++;
        }
        
        return res + 1;
    }
};