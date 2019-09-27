// Sliding window

class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int n = A.length;
        // Elements in the interval which contains less than K distict elements
        Map<Integer, Integer> less = new HashMap<>();
        // Elements in the interval which contains less or equal than K distince element
        Map<Integer, Integer> lessEqual = new HashMap<>();
    
        
        int sl = 0, sle = 0;
        int res = 0;
        
        for (int hi = 0; hi < n; hi++) {
            less.put(A[hi], less.getOrDefault(A[hi], 0) + 1);
            lessEqual.put(A[hi], lessEqual.getOrDefault(A[hi], 0) + 1);
            
            // Move the starting pointer of two intervals to the right
            while (less.size() > K) {
                less.put(A[sl], less.get(A[sl]) - 1);
                if (less.get(A[sl]) == 0)    less.remove(A[sl]);
                sl++;
            }
            
            while (lessEqual.size() >= K) {
                lessEqual.put(A[sle], lessEqual.get(A[sle]) - 1);
                if (lessEqual.get(A[sle]) == 0)    lessEqual.remove(A[sle]);
                sle++;
            }
            
            res += sle - sl;
        }
        
        return res;
    }
}