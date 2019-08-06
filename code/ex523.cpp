// Prefix sum and hash table

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();    if (n <= 1)    return false;
        
        // Build prefix sum array
        vector<int> prefix = vector<int>(n);    prefix[0] = nums[0];
        for (int i = 1; i < n; i++)    prefix[i] = prefix[i - 1] + nums[i];
        
        // Maintain a hash table for all prefixes
        unordered_map<int, int> m;    m.insert({0, -1});
        
        for (int i = 0; i < n; i++) {
            // Find if the mod of k exists in the hash table
            // If exists, then there must be a subarray with sum can be divided by k
            int mod = (k == 0) ? prefix[i] : prefix[i] % k;
            
            if (m.find(mod) != m.end() && m[mod] < i - 1)    return true;
            if (m.find(mod) == m.end())    m[mod] = i;
        }
        
        return false;
    }
};