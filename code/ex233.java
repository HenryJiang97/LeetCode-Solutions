class Solution {
    public int countDigitOne(int n) {
        // Calculate the digit of n
        long digit = 0;
        for (int _n = n; _n != 0; _n /= 10)    digit++;
        
        // Calculate the cnt of '1' appear on each digit
        long cnt = 0;
        for (long i = 0, divisor = 10; i < digit; i++, divisor *= 10) {
            long remaining = Math.min(Math.max(0, n % divisor - divisor / 10 + 1), divisor / 10);
            cnt = cnt + n / divisor * (divisor / 10) + remaining;
        }
        
        return (int)cnt;
    }
}