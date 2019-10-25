// O(n ^ 2)

class Solution {
    public static int mod = (int)1e9 + 7;
    
    public int threeSumMulti(int[] A, int target) {
        int n = A.length;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            // The same as two sum O(n) approach
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int j = i + 1; j < n; j++) {
                int t = target - A[i] - A[j];
                if (cnt.containsKey(t))
                    res = (res + cnt.get(t)) % mod;
                cnt.put(A[j], cnt.getOrDefault(A[j], 0) + 1);
            }
        }
        
        return res;
    }
}