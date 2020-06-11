class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int p0 = 0;    // Right most pointer of group of '0'
        int p2 = n - 1;    // Left most pointer of group of '2'
        int cur = 0;    // Current pointer
        while (p0 < n && nums[p0] == 0)    p0++;
        while (p2 >= 0 && nums[p2] == 2)    p2--;
        cur = p0;
        
        while (cur <= p2) {
            if (nums[cur] == 1)    cur++;
            else if (nums[cur] == 0) {
                // Swap cur with p0
                int temp = nums[cur];
                nums[cur] = nums[p0];
                nums[p0] = temp;
                p0++;    cur++;
            } else {
                // Swap cur with p2
                int temp = nums[cur];
                nums[cur] = nums[p2];
                nums[p2] = temp;
                p2--;
            }
        }
    }
};