class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int n = nums.size();    if (n == 1)    return 0;
        int MAX = 1, len = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
            } else {
                MAX = max(MAX, len);
                len = 1;
            }
        }
        
        return MAX;
    }
};