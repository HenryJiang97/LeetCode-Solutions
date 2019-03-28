// (a ^ 10) % 1337 = (a % 1337) ^ 10


class Solution {
    // Get (a ^ b) % 1337
    public int pow(int a, int b) {
        int res = 1;
        for (int i = 0; i < b; i++) {
            res = (res * a) % 1337;
        }
        return res;
    }
    
    
    public int superPow(int a, int[] b) {       
        int product = 1;   
        a %= 1337;
        
        for (int i = b.length - 1, digit = 1; i >= 0; i--, digit *= 10) {
            product = (product * pow(a, b[i])) % 1337;
            a = pow(a, 10);    // Get a <= a ^ 10 for next digit
        }
        
        return product;
    }
}