// Left and right arrays

class Solution {
    public int longestMountain(int[] A) {
        int n = A.length;    if (n == 0)    return 0;
        
        int[] left = new int[n];    left[0] = 1;
        int[] right = new int[n];    right[n - 1] = 1;
        
        for (int i = 1; i < n; i++) {
            left[i] = A[i - 1] < A[i] ? left[i - 1] + 1 : 1;
            int ri = n - 1 - i;
            right[ri] = A[ri] > A[ri + 1] ? right[ri + 1] + 1 : 1; 
        }
        
        // Get result
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] == 1 || right[i] == 1)    continue;
            max = Math.max(max, left[i] + right[i] - 1);
        }
        
        return max;
    }
}

// Left:  [1, 1, 2, 3, 1, 1, 2]
// Right: [2, 1, 1, 3, 2, 1, 1]

// Left:  [1, 1, 1]
// Right: [1, 1, 1]