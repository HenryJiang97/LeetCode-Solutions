class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        int MAX = 0, prev1 = 0, one = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] == nums[i - 1]) {
                if (nums[i] == 0)    zero++;
                else    one++;
            } else {
                if (nums[i - 1] == 1) {
                    MAX = max(MAX, one);
                    if (zero <= 1)    MAX = max(MAX, prev1 + one);
                    prev1 = one;    one = 0;    zero = 0;
                }
                if (nums[i] == 0)    zero++;
                else    one++;
            }
        }
        return MAX == n - 1 ? MAX - 1 : MAX;
    }
};