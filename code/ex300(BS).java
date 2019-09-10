// Greedy & Binary search

class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> LIS = new ArrayList<>();
        
        for (int num : nums) {
            if (LIS.isEmpty() || num > LIS.get(LIS.size() - 1)) {
                LIS.add(num);
            }
            else if (num < LIS.get(0)) {
                LIS.set(0, num);
            }
            else {
                // Binary search for the num in the list which is just equal or greater than num and set it to num
                int lo = 0, hi = LIS.size() - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (LIS.get(mid) == num)    break;
                    else if (LIS.get(mid) > num) {
                        hi = mid - 1;
                    }
                    else {
                        if (LIS.get(mid + 1) > num) {
                            LIS.set(mid + 1, num);
                            break;
                        }
                        lo = mid + 1;
                    }
                }
            }
        }
        
        return LIS.size();
    }
}