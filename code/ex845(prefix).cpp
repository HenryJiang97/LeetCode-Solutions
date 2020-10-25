class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> prefix(n);
        for (int i = 0; i < n; i++)
            prefix[i] = i == 0 || A[i - 1] >= A[i] ? 1 : prefix[i - 1] + 1;
        
        int MAX = 0, suffix = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix = i == n - 1 || A[i + 1] >= A[i] ? 1 : suffix + 1;
            if (suffix > 1 && prefix[i] > 1)
                MAX = max(MAX, prefix[i] + suffix - 1);
        }
        
        return MAX;
    }
};