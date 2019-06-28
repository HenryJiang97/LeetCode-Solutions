// Map & prefix tree

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();    if (n == 0)    return 0;
        int cnt = 0;
        
        for (int c1 = 0; c1 < n; c1++) {
            int rowSum[m] = {0};
            for (int c2 = c1; c2 < n; c2++) {
                // Get the sum of each row from c1 to c2
                for (int r = 0; r < m; r++)    rowSum[r] += matrix[r][c2];
                
                // Generates map to store former sums
                int sum = 0;
                unordered_map<int, int> map;    map[0] = 1;
                
                for (int r = 0; r < m; r++) {
                    sum += rowSum[r];
                    if (map.find(sum - target) != map.end())    cnt += map[sum - target];
                    
                    if (map.find(sum) != map.end())    map[sum]++;
                    else    map[sum] = 1;
                }
            }
        }
        
        return cnt;
    }
};