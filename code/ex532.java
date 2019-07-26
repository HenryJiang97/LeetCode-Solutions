// Two pointers

class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0)    return 0;
        
        Arrays.sort(nums);
        
        int p1 = 0, p2 = 1, last1 = Integer.MIN_VALUE, last2 = Integer.MIN_VALUE;
        int cnt = 0;
        while (p2 < nums.length) {
            if (p1 >= p2)    {p2++;    continue;}    // Reject p1 from overriding p2
            if (nums[p1] == last1)    {p1++;    continue;}    // Skip duplicates

            if (nums[p2] == nums[p1] + k) {
                cnt++;
                last1 = nums[p1];    last2 = nums[p2];
                p2++;    p1++;
            } else if (nums[p2] < nums[p1] + k)
                p2++;
            else
                p1++;
        }
        
        return cnt;
    }
}