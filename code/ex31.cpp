class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // 1. From right to left, find the first num which violates the ascending trend
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1])    break;
            i--;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int a = i;
        
        // 2. From right to left, find the first num which is larger than nums[a]
        i = n - 1;
        while (i > a) {
            if (nums[i] > nums[a])    break;
            i--;
        }
        int b = i;
        
        // 3. Swap nums[a] with nums[b]
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        
        // 4. Reverse the part after a
        int lo = a + 1, hi = n - 1;
        while (lo < hi) {
            temp = nums[lo];
            nums[lo++] = nums[hi];
            nums[hi--] = temp;
        }
    }
};