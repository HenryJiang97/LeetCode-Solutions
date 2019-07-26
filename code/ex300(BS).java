class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] tail = new int[nums.length];
        int size = 0;

        for (int n : nums) {
            int h = 0, t = size;
            // Binary search in tail array for n
            while (h < t) {
                int mid = (h + t) / 2;
                if (tail[mid] < n)    h = mid + 1;
                else    t = mid;
            }

            // Update tail array;
            tail[h] = n;
            if (h == size)    size++;
        }
        
        return size;
    }
}