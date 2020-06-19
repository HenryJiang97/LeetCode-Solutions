class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix{0};
        for (int i = 0; i < n; i++)
            prefix.push_back(prefix.back() + nums[i]);
        
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n && prefix[i] == prefix[n] - prefix[i + 1])
                return i;
        }
        
        return -1;
    }
};