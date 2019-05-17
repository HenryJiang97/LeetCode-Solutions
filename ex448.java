import java.util.*;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Arrays.sort(nums);
        int p = 0, i = 1;
        // Check which number in the sorted list is missing
        while (p < nums.length) {
            if (nums[p] == i) {
                p++;    i++;
            } else if (nums[p] < i) {
                p++;
            } else {
                res.add(i++);
            }
        }
        // Add the rest missing numbers to result
        for (int a = i; a <= nums.length; a++) {
            res.add(a);
        }
        return res;
    }
}