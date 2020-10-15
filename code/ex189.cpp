class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());    // Reverse entire
        reverse(nums.begin(), nums.begin() + k);    // Reverse front k
        reverse(nums.begin() + k, nums.end());    // Reverse last n - k
    }
};