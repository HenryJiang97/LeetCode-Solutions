class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;    // AND
            a = a ^ b;    // XOR
            b = carry << 1;
        }
        return a;
    }
}