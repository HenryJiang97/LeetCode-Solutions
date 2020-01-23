class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10)    return n;
        
        // Get the digits of the number where nth digit is in
        n -= 9;
        int digits = 2;
        while (n - (pow(10, digits) - pow(10, digits - 1)) * digits > 0) {
            n -= (pow(10, digits) - pow(10, digits - 1)) * digits;
            digits++;
        }
        
        // Get the number this digit is in
        n--;
        long long num = n / digits + pow(10, digits - 1);
        int d = n % digits;    // The digit in the num

        return to_string(num)[d] - '0';
    }
};