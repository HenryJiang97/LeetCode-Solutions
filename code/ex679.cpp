class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> res(nums.begin(), nums.end());
        return backtracking(res);
    }
    
private:
    bool backtracking(vector<double>& res) {
        if (res.size() == 1)    return abs(res[0] - 24.0) < 1e-4;
        
        // Pick two cards
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res.size(); j++) {
                if (i == j)    continue;
                vector<double> newRes;
                for (int k = 0; k < res.size(); k++) {
                    if (k != i && k != j)    newRes.push_back(res[k]);
                }
                
                // +
                newRes.push_back(res[i] + res[j]);
                if (backtracking(newRes))    return 1;
                newRes.pop_back();

                // -
                newRes.push_back(res[i] - res[j]);
                if (backtracking(newRes))    return 1;
                newRes.pop_back();

                // *
                newRes.push_back(res[i] * res[j]);
                if (backtracking(newRes))    return 1;
                newRes.pop_back();
                
                // /
                if (res[j] != 0) {
                    newRes.push_back(res[i] / res[j]);
                    if (backtracking(newRes))    return 1;
                    newRes.pop_back();
                }
            }
        }
        
        return 0;
    }
};