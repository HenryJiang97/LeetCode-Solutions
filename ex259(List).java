import java.util.ArrayList;

class Solution {
    public int[] singleNumber(int[] nums) {
        ArrayList<Integer> r = new ArrayList<>();
        
        for (int i = 0; i < nums.length; i++) {
            if (!r.contains(nums[i]))
                r.add(nums[i]);
            else
                // Remove the item in the list
                for (int j = r.size() - 1; j >= 0; j--){
                    if (r.get(j) == nums[i]) {
                        r.remove(j);
                        break;
                    }
                }
        }

        // Copy r to result array
        int[] result = new int[r.size()];

        for (int i = 0; i < result.length; i++)
            result[i] = r.get(i);

       
        return result;
    }
}