class Solution {
    public boolean isPowerOfFour(int num) {
        if (num == 1)    return true;
        while (num > 4 && num % 4 == 0)    num = num >> 2;
        return (num == 4) ? true : false;
    }
}

// Bit manipulation
class Solution {
    public boolean isPowerOfFour(int num) {
        return (num > 0) && ((num & (num-1)) == 0) && ((0x55555554 & num) == num || (num == 1));
    }
}