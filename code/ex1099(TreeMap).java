// TreeMap

class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int n = A.length;
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int a : A) {
            map.put(a, map.getOrDefault(a, 0) + 1);
        }
        
        int max = -1;
        for (int a : A) {
            if (a >= K)    continue;
            
            int second = K - a;
            Integer lower = map.lowerKey(second);
            if (lower != null) {
                if (lower == a && map.get(a) < 2)    continue;
                max = Math.max(max, a + map.lowerKey(second));
            }
        }
        
        return max;
    }
}