class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long cnt = 0, missing = 1, i = 0;
        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) {    // Can cover curring missing
                missing += nums[i++];
            } else {
                cnt++;
                missing += missing;
            }
        }
        return (int)cnt;
    }
};