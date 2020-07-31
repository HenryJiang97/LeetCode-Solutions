class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        
        multimap<int, int> val2arr;    // Val -> array
        vector<int> idx(n);    // arr -> idx
        
        for (int i = 0; i < n; i++)    val2arr.insert({nums[i][0], i});
        
        int MIN = INT_MAX;
        vector<int> res{-1, -1};
        while (1) {
            auto it = val2arr.begin();
            auto a1 = *val2arr.begin(), a2 = *val2arr.rbegin();
            if (a2.first - a1.first < MIN) {
                MIN = a2.first - a1.first;
                res[0] = a1.first, res[1] = a2.first;
            }
            
            if (idx[a1.second] + 1 >= nums[a1.second].size())
                break;
            else {
                idx[a1.second]++;
                val2arr.insert({nums[a1.second][idx[a1.second]], a1.second});
                val2arr.erase(it);
            }
        }
        
        return res;
    }
};