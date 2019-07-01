class Solution {
    public int oddEvenJumps(int[] A) {
        int n = A.length;
        if (n <= 1)    return n;
        
        // Build dp array
        boolean[] dp_odd = new boolean[n];
        boolean[] dp_even = new boolean[n];
        dp_odd[n - 1] = true;    dp_even[n - 1] = true;
        
        // Build treemap
        TreeMap<Integer, Integer> treemap = new TreeMap<>();
        treemap.put(A[n - 1], n - 1);
        
        for (int i = n - 2; i >= 0; i--) {
            Integer odd_next = treemap.ceilingKey(A[i]);
            Integer even_next = treemap.floorKey(A[i]);

            dp_odd[i] = odd_next == null ? false : dp_even[treemap.get(odd_next)];
            dp_even[i] = even_next == null ? false : dp_odd[treemap.get(even_next)];
            
            treemap.put(A[i], i);
        }
        
        // Get results
        int res = 0;
        for (int i = 0; i < n; i++)
            if (dp_odd[i])    res++;
        
        return res;
    }
}