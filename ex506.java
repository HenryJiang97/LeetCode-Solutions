class Solution {
    public String[] findRelativeRanks(int[] nums) {
        String[] medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        TreeMap<Integer, Integer> treemap = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++)    treemap.put(nums[i], i);
        
        String[] res = new String[nums.length];
        int rank = 0;
        for (Map.Entry<Integer, Integer> entry : treemap.entrySet()) {
            if (rank < 3)    res[entry.getValue()] = medals[rank];
            else    res[entry.getValue()] = String.valueOf(rank + 1);
            rank++;
        }
        
        return res;
    }
}