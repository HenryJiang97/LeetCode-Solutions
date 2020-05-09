class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();    if (n == 0)    return 0;
        
        int MAX = INT_MIN;
        for (int c1 = 0; c1 < n; c1++) {
            vector<int> prefix(m);
            
            for (int c2 = c1; c2 < n; c2++) {
                int sum = 0;
                set<int> s;    s.insert(0);
                
                for (int r = 0; r < m; r++) {
                    prefix[r] += matrix[r][c2];
                    sum += prefix[r];
                    
                    int targetMin = sum - k;
                    if (*s.rbegin() >= targetMin)
                        MAX = max(MAX, sum - *s.lower_bound(targetMin));
                    
                    s.insert(sum);
                }
            }
        }
        
        return MAX;
    }
};