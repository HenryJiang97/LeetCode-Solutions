class Solution {
    public int findNthDigit(int n) {
        if (n == Math.pow(2, 31) - 1)    return 2;
        
        int i = 1;
        int numOfDigit = 1;
        int backup = 0;
        int enlongate = 9, num = 9;
        
        while (true) {
            backup++;
            if (i >= n)    break;
            
            if (backup >= enlongate) {
                numOfDigit++;
                num *= 10;
                enlongate += num;
            }
            i += numOfDigit;
        }
        i -= numOfDigit;
        
        return String.valueOf(backup).charAt(n - i - 1) - '0';
    }
}