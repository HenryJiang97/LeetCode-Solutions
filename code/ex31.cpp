class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // 1. From right to left, find the first num which violates the ascending or equal trend
        int a = n - 2;
        while (a >= 0 && nums[a] >= nums[a + 1])    a--;
        if (a < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        // 2. From right to left, find the first num which is larger than nums[a]
        int b = n - 1;
        while (b > a + 1 && nums[b] <= nums[a])    b--;
        
        // 3. Swap nums[a] with nums[b]
        swap(nums[a], nums[b]);
        
        // 4. Reverse the part after a
        int lo = a + 1, hi = n - 1;
        while (lo < hi) {
            swap(nums[lo++], nums[hi--]);
        }
    }
};