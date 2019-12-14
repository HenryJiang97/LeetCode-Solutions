class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z > x + y || z < 0)    return false;
        return (z == 0 || z % gcd(x, y) == 0);
    }
    
    private int gcd(int a, int b) {
        if (b == 0)    return a;
        return gcd(b, a % b);
    }
}