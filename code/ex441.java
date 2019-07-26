// Math, Solve ((1 + x) * x) / 2 <= n

class Solution {
    public int arrangeCoins(int n) {
        return (int)((-1 + Math.sqrt(1 + 8 * (double)n)) / 2);
    }
}