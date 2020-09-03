class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int idx = -1, MIN = INT_MAX, prefix = 0;
        for (int i = 0; i < n; i++) {    // Find the idx where prefix sum is minimum
            prefix += gas[i] - cost[i];
            if (prefix < MIN) {
                MIN = prefix;
                idx = i;
            }
        }
        if (prefix < 0)    return -1;
        
        return idx + 1 < n ? idx + 1 : 0;
    }
};