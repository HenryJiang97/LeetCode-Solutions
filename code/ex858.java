class Solution {
    public int mirrorReflection(int p, int q) {
        int m = lcd(p, q) / q;
        int n = lcd(p, q) / p;
        return m % 2 == 0 ? 2 : n % 2;
    }
    
    private int lcd(int a, int b) {
        return a * b / gcd(a, b);
    }
    
    private int gcd(int a, int b) {
        if (b == 0)    return a;
        return gcd(b, a % b);
    }
}