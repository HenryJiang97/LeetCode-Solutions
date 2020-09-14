class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        
        vector<int> improvement(n + 1);
        for (int i = 0; i < n; i++) {
            improvement[i + 1] = (grumpy[i] == 1 ? customers[i] : 0) + improvement[i];
        }
        
        // Sliding window
        int MAX = INT_MIN, idx = -1;
        for (int i = 0; i + X - 1 < n; i++) {
            int impro = improvement[i + X] - improvement[i];
            if (impro > MAX) {
                MAX = impro;
                idx = i;
            }
        }
        
        // Get result
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (i >= idx && i < idx + X || grumpy[i] == 0) ? customers[i] : 0;
        }
        
        return res;
    }
};