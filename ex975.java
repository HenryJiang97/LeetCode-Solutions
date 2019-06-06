// DP, TreeMap: key=>the value at position i; value=>the next index

import java.util.*;

class Solution {
    public int oddEvenJumps(int[] A) {
        int n = A.length;
        boolean[] dp_odd = new boolean[n];
        boolean[] dp_even = new boolean[n];
        dp_odd[n - 1] = true;    dp_even[n - 1] = true;
        
        // Treemap to store the next valid jump destination for position i
        TreeMap<Integer, Integer> treemap = new TreeMap<>();
        treemap.put(A[n - 1], n - 1);
        
        // Build dp array
        for (int i = n - 2; i >= 0; i--) {
            int k = A[i];
            // Get from treemap
            if (treemap.containsKey(k)) {
                dp_odd[i] = dp_even[treemap.get(k)];
                dp_even[i] = dp_odd[treemap.get(k)];
            } else {
                int index_odd = treemap.higherKey(k) == null ? -1 : treemap.higherKey(k);
                int index_even = treemap.lowerKey(k) == null ? -1 : treemap.lowerKey(k);
                dp_odd[i] = index_odd != -1 ? dp_even[treemap.get(index_odd)] : false;
                dp_even[i] = index_even != -1 ? dp_odd[treemap.get(index_even)] : false;
            }
            treemap.put(k, i);
        }
        
        // Get the result
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dp_odd[i])    cnt++;
        }
        return cnt;
    }
}