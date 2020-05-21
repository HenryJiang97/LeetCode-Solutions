class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int MAX = 0;
        unordered_map<int, int> m;
        for (int n : nums)    m[n]++;
        
        for (int num : nums) {
            if (m.find(num + 1) != m.end())
                MAX = max(MAX, m[num] + m[num + 1]);
        }      
        return MAX;
    }
};