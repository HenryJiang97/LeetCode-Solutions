class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int d : deck)    cnt.put(d, cnt.getOrDefault(d, 0) + 1);
        int GCD = -1;
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            if (GCD == -1)    GCD = entry.getValue();
            GCD = gcd(GCD, entry.getValue());
        }
        return GCD >= 2;
    }
    
    private int gcd(int a, int b) {
        if (b == 0)    return a;
        return gcd(b, a % b);
    }
}