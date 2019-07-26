class Solution {
    public String addStrings(String num1, String num2) {
        int carry = 0;
        int p1 = num1.length() - 1, p2 = num2.length() - 1;
        String res = "";
        
        while (p1 >= 0 && p2 >= 0) {
            int d = (num1.charAt(p1) - '0') + (num2.charAt(p2) - '0');
            res = String.valueOf((d + carry) % 10 ) + res;
            carry = (d + carry) / 10;
            p1--;    p2--;
        }
        
        while (p1 >= 0) {
            int d = num1.charAt(p1) - '0';
            res = String.valueOf((d + carry) % 10) + res;
            carry = (d + carry) / 10;
            p1--;
        }
        
        while (p2 >= 0) {
            int d = num2.charAt(p2) - '0';
            res = String.valueOf((d + carry) % 10) + res;
            carry = (d + carry) / 10;
            p2--;
        }

        return carry == 0 ? res : String.valueOf(carry) + res;
    }
}