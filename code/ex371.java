class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;    // carry => AND
            a = a ^ b;    // sum => XOR
            b = carry << 1;
        }
        return a;
    }
}