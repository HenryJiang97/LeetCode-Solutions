import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> r = new HashSet<>();
        List<Integer> record = new ArrayList<>();
        int lo, hi;
        int sum;

        
        // Sort the array first
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length - 3; i++) {
            for (int j = i + 1; j < nums.length - 2; j++) {
                lo = j + 1;
                hi = nums.length - 1;
            
                while (lo < hi) {
                    sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                
                    if (sum == target) {
                        // Add item to list
                        record.add(nums[i]);
                        record.add(nums[j]);
                        record.add(nums[lo]);
                        record.add(nums[hi]);

                        // Add list ot set
                        r.add(new ArrayList<>(record));
                        record.clear();
                        hi--;   lo++;
                    } else if (sum > target)    hi--;
                    else    lo++;
                }
            }
        }

        
        return new ArrayList<>(r);
    }
}