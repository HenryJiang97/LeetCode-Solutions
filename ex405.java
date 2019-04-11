// Negative num => num + 2^32

class Solution {
    public String toHex(int num) {
        if (num >= 0)    return hex_cal((long)num);
        else    return hex_cal((long)num + (long)Math.pow(2, 32));
    }
    
    public String hex_cal(long num) {
        if (num == 0)    return "0";
        String res = "";
        for (; num > 0; num /= 16) {
            int r = (int)(num % 16);
            if (r >= 10) {
                res = Character.toString(Character.toChars('a' + r - 10)[0]) + res;
            } else {
                res = String.valueOf(r) + res;
            }
        }
        return res;
    }
}