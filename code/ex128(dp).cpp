// DP

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return 0;
        
        unordered_map<int, int> map;
        for (int num : nums)    map[num] = 1;
        
        int MAX = 1;
        for (auto& [num, cnt] : map) {
            if (map[num] != 1)    MAX = max(MAX, map[num]);
            else    MAX = max(MAX, backtracking(map, num));
        }
        
        return MAX;
    }
    
private:
    int backtracking(unordered_map<int, int>& map, int s) {
        if (map.find(s) == map.end())    return 0;
        if (map[s] != 1)    return map[s];
        int res = backtracking(map, s + 1) + 1;
        map[s] = res;
        return res;
    }
};