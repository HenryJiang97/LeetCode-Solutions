// Greedy

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        
        int cnt = 0;
        for (int i = 0; i < n - 1; i += 2) {
            int first = row[i];
            int second = row[i] ^ 1;
            
            if (row[i + 1] == second)    continue;    // Couples already sit together
            
            for (int j = i + 2; j < n; j++) {
                if (row[j] == second) {
                    // Swap row[j] with row[i + 1]
                    row[j] = row[i + 1];
                    row[i + 1] = second;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};