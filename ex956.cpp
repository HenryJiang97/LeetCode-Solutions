class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int maxdiff = 0;
        for (auto& rod : rods)    maxdiff += rod;
        auto memo = vector<vector<int>>(maxdiff + 1, vector<int>(rods.size()));
        return recurrsion(rods, 0, 0, memo);
    }
    
    int recurrsion(vector<int>& rods, int diff, int index, vector<vector<int>>& memo) {
        if (index >= rods.size()) {
            if (diff != 0)    return INT_MIN;
            else    return 0;
        }
        
        // Load memo
        if (memo[diff][index] != 0)    return memo[diff][index];
        
        int addlongleg = recurrsion(rods, diff + rods[index], index + 1, memo);
        int addshortleg = recurrsion(rods, std::abs(diff - rods[index]), index + 1, memo) + min(diff, rods[index]);
        int notadd = recurrsion(rods, diff, index + 1, memo);
        
        // Save memo
        memo[diff][index] = max(addlongleg, max(addshortleg, notadd));
        return memo[diff][index];
    }
};